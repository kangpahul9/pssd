#include <bits/stdc++.h>
using namespace std;

class MooingCows {
public:
    int dissatisfaction(vector<string> farmland) {
        int R = (int)farmland.size();
        int C = (int)farmland[0].size();

        vector<int> xs, ys;
        for (int i = 0; i < R; ++i) {
            for (int j = 0; j < C; ++j) {
                if (farmland[i][j] == 'C') {
                    xs.push_back(i);
                    ys.push_back(j);
                }
            }
        }
        int N = (int)xs.size();

        int sumX = 0, sumY = 0, sumX2 = 0, sumY2 = 0;
        for (int k = 0; k < N; ++k) {
            int x = xs[k], y = ys[k];
            sumX += x; sumY += y;
            sumX2 += x * x; sumY2 += y * y;
        }

        int best = INT_MAX;
        for (int k = 0; k < N; ++k) {
            int x = xs[k], y = ys[k];
            int valX = N * x * x - 2 * x * sumX + sumX2;
            int valY = N * y * y - 2 * y * sumY + sumY2;
            int total = valX + valY;
            if (total < best) best = total;
        }
        return best;
    }
};
