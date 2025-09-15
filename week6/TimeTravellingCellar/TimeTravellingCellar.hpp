#include <bits/stdc++.h>
using namespace std;

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
                    continue; 
                maxProfit = max(maxProfit, profit[i] - decay[j]);
            }
        }
        return maxProfit;
    }
};

