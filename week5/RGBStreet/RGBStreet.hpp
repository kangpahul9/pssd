#include<bits/stdc++.h>
using namespace std;

class RGBStreet
{    
public:
    int estimateCost(vector<string> houses){
        int n=houses.size();
        vector<vector<int>> cost(n, vector<int>(3));
        vector<vector<int>> dp(n, vector<int>(3));

        for (int i = 0; i < n; i++)
        {
            istringstream iss(houses[i]);
            int R, G, B;
            iss >> R >> G >> B;
            cost[i][0]=R;
            cost[i][1]=G;
            cost[i][2]=B;
        }
        dp[0][0] = cost[0][0];
        dp[0][1] = cost[0][1];
        dp[0][2] = cost[0][2];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = cost[i][0] + min(dp[i-1][1], dp[i-1][2]); // paint red
            dp[i][1] = cost[i][1] + min(dp[i-1][0], dp[i-1][2]); // paint green
            dp[i][2] = cost[i][2] + min(dp[i-1][0], dp[i-1][1]); // paint blue
        }
        int answer = min(dp[n-1][0], dp[n-1][1], dp[n-1][2]);
        return answer;
    }
};
