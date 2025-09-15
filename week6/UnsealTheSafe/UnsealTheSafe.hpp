#include <bits/stdc++.h>
using namespace std;
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