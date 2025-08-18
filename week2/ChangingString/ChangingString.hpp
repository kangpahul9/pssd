#include <bits/stdc++.h>
using namespace std;

class ChangingString {
public:
    int distance(string A, string B, int K) {
        int n = (int)A.size();
        vector<int> d(n);
        int sum = 0, nonZero = 0;

        for (int i = 0; i < n; ++i) {
            d[i] = std::abs((int)A[i] - (int)B[i]);
            sum += d[i];
            if (d[i] > 0) ++nonZero;
        }

        sort(d.begin(), d.end()); 

        if (K <= nonZero) {
            for (int i = n - 1; i >= n - K; --i) sum -= d[i];
            return sum;
        } else {
            return K - nonZero;
        }
    }
};
