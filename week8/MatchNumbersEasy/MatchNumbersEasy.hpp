#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector<int> matches, int n) {
        vector<string> dp(n + 1, "#");
        dp[0] = "";

        for (int i = 0; i <= n; i++) {
            if (dp[i] == "#") continue;
            for (int d = 0; d < (int)matches.size(); d++) {
                int cost = matches[d];
                if (i + cost <= n) {
                    if (dp[i].empty() && d == 0 && cost != n) continue;
                    string candidate = dp[i] + (char)('0' + d);
                    if (dp[i + cost] == "#" || isBigger(candidate, dp[i + cost]))
                        dp[i + cost] = candidate;
                }
            }
        }

        string best = "";
        for (int i = 0; i <= n; i++) {
            if (dp[i] != "#" && isBigger(dp[i], best))
                best = dp[i];
        }
        if (best.empty()) return "0";

        while (best.size() > 1 && best[0] == '0')
            best.erase(best.begin());

        return best;
    }

    bool isBigger(const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};
