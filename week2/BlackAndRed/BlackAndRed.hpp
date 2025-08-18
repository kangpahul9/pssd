#include <bits/stdc++.h>
using namespace std;

class BlackAndRed {
public:
    int cut(string deck) {
        int n = (int)deck.size();
        vector<int> c(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            int v = (deck[i] == 'R') ? 1 : -1;
            c[i + 1] = c[i] + v;
        }
        int p = 0;        
        int m = c[0];     
        for (int i = 1; i <= n; ++i) {
            if (c[i] > m) {
                m = c[i];
                p = i;
            }
        }
        return p % n;
    }
};
