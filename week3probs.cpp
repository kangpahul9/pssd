#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Arrows
{
public:
    int longestArrow(string s)
    {
        int n = s.size();
        int best = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                // Left single arrow "<-..."
                int len = 1;
                int j = i + 1;
                while (j < n && s[j] == '-')
                {
                    len++;
                    j++;
                }
                best = max(best, len);

                // Left double arrow "<=..."
                len = 1;
                j = i + 1;
                while (j < n && s[j] == '=')
                {
                    len++;
                    j++;
                }
                best = max(best, len);
            }
            else if (s[i] == '>')
            {
                // Right single arrow "...->"
                int len = 1;
                int j = i - 1;
                while (j >= 0 && s[j] == '-')
                {
                    len++;
                    j--;
                }
                best = max(best, len);

                // Right double arrow "...=>"
                len = 1;
                j = i - 1;
                while (j >= 0 && s[j] == '=')
                {
                    len++;
                    j--;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};

class QuickSums
{
public:
    int minSums(string numbers, int sum)
    {
        int ans = dfs(numbers, 0, sum);
        return (ans >= INT_MAX / 2) ? -1 : ans;
    }
    int dfs(string s, int idx, int target)
    {
        if (idx == s.size())
        {
            return (target == 0 ? 0 : INT_MAX / 2);
        }
        int res = INT_MAX / 2;
        long long num = 0;
        for (int i = idx; i < s.size(); i++){
            num = num * 10 + (s[i] - '0');
            if (num > target) break;
            int next = dfs(s, i + 1, target - num);
            if (next != INT_MAX / 2)
            {
                // if not at last cut, we need +1 addition
                if (i + 1 < s.size())
                    res = min(res, 1 + next);
                else
                    res = min(res, next);
            }
        }
            return res;

    }
};int main()
{
    Arrows solver;

    // Test Arrows
    cout << "Arrows Tests:" << endl;
    cout << "Test 0: " << solver.longestArrow("<--->--==>") << " (Expected: 4)" << endl;
    cout << "Test 1: " << solver.longestArrow("<<<<<<<<<<") << " (Expected: 1)" << endl;
    cout << "Test 2: " << solver.longestArrow("----==-") << " (Expected: -1)" << endl;
    cout << "Test 3: " << solver.longestArrow("<----=====>") << " (Expected: 6)" << endl;

    QuickSums qs;

    // Test QuickSums
    cout << "\nQuickSums Tests:" << endl;
    cout << "Test 0: " << qs.minSums("99999", 45) << " (Expected: 4)" << endl;
    cout << "Test 1: " << qs.minSums("1110", 3) << " (Expected: 3)" << endl;
    cout << "Test 2: " << qs.minSums("0123456789", 45) << " (Expected: 8)" << endl;
    cout << "Test 3: " << qs.minSums("99999", 100) << " (Expected: -1)" << endl;
    cout << "Test 4: " << qs.minSums("382834", 100) << " (Expected: 2)" << endl;
    cout << "Test 5: " << qs.minSums("9230560001", 71) << " (Expected: 4)" << endl;

    return 0;
}