#include <bits/stdc++.h>
using namespace std;

class PartySeats {
public:
    vector<string> seating(const vector<string>& attendees) {
        vector<string> boys, girls, result;

        for (const string& s : attendees) {
            size_t pos = s.rfind(' ');
            if (pos == string::npos) return {};
            string name = s.substr(0, pos);
            string gender = s.substr(pos + 1);
            if (gender == "boy") boys.push_back(name);
            else if (gender == "girl") girls.push_back(name);
            else return {};
        }

        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());

        int n = (int)attendees.size();
        if (boys.size() != girls.size()) return {};
        if ((int)girls.size() < 2) return {};
        if (n % 4 != 0) return {};             

        int total = n + 2;
        int mid = total / 2;                   
        result.resize(total);

        result[0] = "HOST";
        result[mid] = "HOSTESS";

        int cb = 0, cg = 0;
        for (int i = 1; i < total; ++i) {
            if (i == mid) continue;
            if (i % 2 == 1) {                   
                result[i] = girls[cg++];
            } else {                            
                result[i] = boys[cb++];
            }
        }
        return result;
    }
};
