#include <bits/stdc++.h>
using namespace std;

class EggCartons {
public:
    int minCartons(int n) {
        int best = INT_MAX;
        for (int x = 0; x <= n / 8; ++x) {          
            int rem = n - 8 * x;
            if (rem >= 0 && rem % 6 == 0) {
                int y = rem / 6;                  
                int total = x + y;
                if (total < best) best = total;
            }
        }
        return (best == INT_MAX) ? -1 : best;
    }
};