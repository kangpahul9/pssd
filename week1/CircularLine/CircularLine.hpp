#include <bits/stdc++.h>
using namespace std;

class CircularLine {
public:
    int longestTravel(vector<int> t) {
        int n = t.size();
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + t[i];
        }
        int totalTime = prefixSum[n];
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {  
                int travelTime = prefixSum[j] - prefixSum[i];   
                int fastest = min(travelTime, totalTime - travelTime); 
                ans = max(ans, fastest);
            }
        }
        return ans;
    }
};