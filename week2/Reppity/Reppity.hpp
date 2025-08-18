#include <string>
using namespace std;

class Reppity {
public:
    int longestRep(string input) {
        int n = (int)input.size();
        for (int L = n / 2; L >= 1; --L) {                 
            for (int i = 0; i + L <= n; ++i) {             
                for (int j = i + L; j + L <= n; ++j) {     
                    bool same = true;
                    for (int k = 0; k < L; ++k) {
                        if (input[i + k] != input[j + k]) { same = false; break; }
                    }
                    if (same) return L;
                }
            }
        }
        return 0;
    }
};