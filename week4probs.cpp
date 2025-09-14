#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long ll;

class TimeTravellingCellar
{
public:
    int determineProfit(vector<int> profit, vector<int> decay)
    {
        int n = profit.size();
        int maxProfit = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue; // cannot use the same cellar
                maxProfit = max(maxProfit, profit[i] - decay[j]);
            }
        }

        return maxProfit;
    }
};

class FriendlySequences
{
public:
    int count(vector<int> array)
    {
        int n = array.size();
        if (n < 2)
            return 0;
        vector<string> sigs(n);
        for (int i = 0; i < n; i++)
            sigs[i] = digits(array[i]);
        return countBlocks(sigs, 0);
    }
    string digits(int number)
    {
        bool digits[10] = {false};
        if (number == 0)
        {
            digits[0] = true;
        }

        string result;
        while (number > 0)
        {
            digits[number % 10] = true;
            number /= 10;
        }
        for (int d = 0; d <= 9; d++)
        {
            if (digits[d])
                result.push_back('0' + d);
        }
        return result;
    }
    int countBlocks(const vector<string> &sigs, int i)
    {
        if (i >= (int)sigs.size())
            return 0;

        int j = i;
        while (j < (int)sigs.size() && sigs[j] == sigs[i])
            j++;
        int len = j - i;
        int res = (len >= 2) ? len * (len - 1) / 2 : 0;

        return res + countBlocks(sigs, j);
    }
};

class PaternityTest

{
public:
    vector<int> possibleFathers(string child, string mother, vector<string> men)
    {
        vector<int> indices;
        int n = child.size();

        for (int i = 0; i < (int)men.size(); i++)
        {
            int fatherMatches = 0;
            bool valid = true;

            for (int j = 0; j < n; j++)
            {
                if (child[j] == mother[j])
                {
                    // Mother explains this position
                    if (child[j] == men[i][j])
                    {
                        fatherMatches++;
                    }
                }
                else
                {
                    // Mother cannot explain -> father must
                    if (child[j] == men[i][j])
                    {
                        fatherMatches++;
                    }
                    else
                    {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && fatherMatches >= n / 2)
            {
                indices.push_back(i);
            }
        }
        return indices;
    }
};

class UnsealTheSafe
{
public:
    long countPasswords(int N)
    {
        vector<vector<int>> neighbors = {
            {7},          // 0
            {2, 4},       // 1
            {1, 3, 5},    // 2
            {2, 6},       // 3
            {1, 5, 7},    // 4
            {2, 4, 6, 8}, // 5
            {3, 5, 9},    // 6
            {4, 8, 0},    // 7
            {5, 7, 9},    // 8
            {6, 8}        // 9
        };
        vector<vector<long>> dp(N + 1, vector<long>(10, 0));
        for (int d = 0; d <= 9; d++)
            dp[1][d] = 1;
        for (int len = 2; len <= N; len++)
        {
            for (int d = 0; d <= 9; d++)
            {
                for (int nb : neighbors[d])
                {
                    dp[len][d] += dp[len - 1][nb];
                }
            }
        }
        long total = 0;
        for (int d = 0; d <= 9; d++)
            total += dp[N][d];

        return total;
    }
};

class MonstersValley2
{
public:
    int minimumPrice(vector<int> dread, vector<int> price)
    {
        int n = dread.size();
        int maxCoins = 2 * n;
vector<vector<long long>> dp(n + 1, vector<long long>(maxCoins + 1, -1));
        dp[0][0] = 0;

        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c < maxCoins; c++)
            {
                if (dp[i][c] == -1)
                    continue;
                long long curDread = dp[i][c];
                dp[i + 1][c + price[i]]= max(dp[i + 1][c + price[i]], curDread + dread[i]);
                if (curDread >= dread[i])
                {
                    dp[i + 1][c] = max(dp[i + 1][c], curDread);
                }
            }
            
        }
        for (int c = 0; c <= maxCoins; c++)
        {
            if (dp[n][c] != -1)
                return c;
        }
        return -1;
    }
};

void runTest(int testNum, string child, string mother, vector<string> men, vector<int> expected)
{
    PaternityTest pt;
    vector<int> res = pt.possibleFathers(child, mother, men);

    cout << "Test " << testNum << ": got { ";
    for (int idx : res)
        cout << idx << " ";
    cout << "}, expected { ";
    for (int idx : expected)
        cout << idx << " ";
    cout << "}" << endl;
}

int main()
{
    TimeTravellingCellar solver;

    cout << solver.determineProfit({1, 2, 3}, {3, 1, 2}) << " (Expected: 2)" << endl;
    cout << solver.determineProfit({3, 2}, {1, 2}) << " (Expected: 1)" << endl;
    cout << solver.determineProfit({3, 3, 3}, {1, 1, 1}) << " (Expected: 2)" << endl;
    cout << solver.determineProfit({1000, 500, 250, 125}, {64, 32, 16, 8}) << " (Expected: 992)" << endl;
    FriendlySequences fs;

    vector<vector<int>> tests = {
        {112, 12, 21, 354, 534345, 345, 2221},
        {10, 1100, 10101, 111, 1111, 11111, 11, 1, 111},
        {0, 0, 0, 0},
        {123456890, 213456890, 198654320},
        {9}};

    vector<int> expected = {6, 18, 6, 3, 0};

    for (size_t i = 0; i < tests.size(); i++)
    {
        int result = fs.count(tests[i]);
        cout << "Test " << i << ": got " << result
             << ", expected " << expected[i] << endl;
    }
    runTest(0, "ABCD", "AXCY", {"SBTD", "QRCD"}, {0});
    runTest(1, "ABCD", "ABCX", {"ABCY", "ASTD", "QBCD"}, {1, 2});
    runTest(2, "ABABAB", "ABABAB", {"ABABAB", "ABABCC", "ABCCDD", "CCDDEE"}, {0, 1});
    runTest(3, "YZGLSYQT", "YUQRWYQT", {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"}, {});
    runTest(4, "WXETPYCHUWSQEMKKYNVP", "AXQTUQVAUOSQEEKCYNVP",
            {"WNELPYCHXWXPCMNKDDXD", "WFEEPYCHFWDNPMKKALIW", "WSEFPYCHEWEFGMPKIQCK",
             "WAEXPYCHAWEQXMSKYARN", "WKEXPYCHYWLLFMGKKFBB"},
            {1, 3});

    // Extra custom tests
    // 5) Smallest case: 2 chars
    runTest(5, "AB", "AC", {"AB", "AD"}, {0}); // first man matches, second ruled out
    // 6) Both mother and father fully match
    runTest(6, "AAAA", "AAAA", {"AAAA", "TTTT"}, {0}); // first man could be father too
    // 7) Only father contributes exactly half
    runTest(7, "ABCD", "AXYZ", {"ABCD", "PQRS"}, {0}); // man 0 needed for BCD
    // 8) Multiple possible fathers
    runTest(8, "AABB", "AAXX", {"YYBB", "AABB", "ZZBB"}, {0, 1, 2});
    // 9) Edge case: longest allowed 20 chars
    runTest(9, "AAAAAAAAAAAAAAAAAAAA", "AAAAAAAAAAAAAAAAAAAA",
            {"AAAAAAAAAAAAAAAAAAAA", "BBBBBBBBBBBBBBBBBBBB"}, {0}); // only man 0 matches

    UnsealTheSafe uts;
    cout << "N=2: " << uts.countPasswords(2) << endl;   // 26
    cout << "N=3: " << uts.countPasswords(3) << endl;   // 74
    cout << "N=4: " << uts.countPasswords(4) << endl;   // 210
    cout << "N=25: " << uts.countPasswords(25) << endl; // 768478331222

    MonstersValley2 mv;
    vector<int> dread = {8, 5, 10};
    vector<int> price = {1, 1, 3};
    cout << "\nMonstersValley2 Test:" << endl;
    cout << "Minimum coins needed: " << mv.minimumPrice(dread, price) << " (Expected: ? depends on DP logic)" << endl;

    return 0;
}
