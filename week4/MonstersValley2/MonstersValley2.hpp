#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class MonstersValley2
{
public:
    int minimumPrice(vector<int> &dread, vector<int> &price)
    {
        int n = dread.size();
        int maxCoins = 2 * n;
        vector<vector<long long>> dp(n + 1, vector<long long>(maxCoins + 1, -1));

        dp[0][0] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int c = 0; c <= maxCoins; c++)
            {
                if (dp[i][c] == -1)
                    continue; // invalid state

                long long curDread = dp[i][c];

                // Option 1: Bribe this monster
                dp[i + 1][c + price[i]] = max(dp[i + 1][c + price[i]], curDread + dread[i]);

                // Option 2: Skip this monster (only if safe)
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