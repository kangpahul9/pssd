#include<iostream>
#include<string>
using namespace std;

class DifferentStrings
{

public:
    int minimize(string A, string B) {
        int n = A.size(), m = B.size();
        int ans = n; 
        for (int i = 0; i + n <= m; i++) {
            int diff = 0;
            for (int j = 0; j < n; j++) {
                if (A[j] != B[i + j])
                    diff++;
            }
            ans = min(ans, diff);
        }
        return ans;
    }
};
