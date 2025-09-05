#include <bits/stdc++.h>
using namespace std;

class Barbecue
{
public:
    int eliminate(int n, vector<int> voter, vector<int> excluded)
    {
        vector<int> votesBy(n, 0);
        vector<int> votesFor(n, 0);

        for (int i = 0; i < voter.size(); i++)
        {
            votesBy[voter[i]]++;
            votesFor[excluded[i]]++;
        }
        int maxValue = 0, maxIndex = 0;
        for (int i = 0; i < n; i++)
        {
            if (votesFor[i] > maxValue)
            {
                maxValue = votesFor[i];
                maxIndex = i;
            }
            else if (votesFor[i] == maxValue)
            {
                if (votesBy[i] > votesBy[maxIndex])
                {
                    maxValue = votesFor[i];
                    maxIndex = i;
                }
                else if (votesBy[i] == votesBy[maxIndex])
                {
                    if (i < maxIndex)
                    {
                        maxValue = votesFor[i];
                        maxIndex = i;
                    }
                    else
                    {
                        continue
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return maxIndex;
    }
};
