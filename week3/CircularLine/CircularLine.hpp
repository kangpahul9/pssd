#include <bits/stdc++.h>
using namespace std;
class CircularLine {
public:
    int longestTravel(vector<int> t) {
        int n = t.size(); 
        int S = accumulate(t.begin(), t.end(), 0);
        vector<int> u = t;
        u.insert(u.end(), t.begin(), t.end()); 
        int ans = 0; int curr = 0; int j = 0;
        for (int i = 0; i < n; i++)
        {
            while (curr + u[j] <= S / 2 && j < i+n)
            {
                curr += u[j++];
                ans = max(ans, curr);
                if (ans == S/2) return ans;
            }
            curr -= u[i];
        }
        return ans;
    }
};

        