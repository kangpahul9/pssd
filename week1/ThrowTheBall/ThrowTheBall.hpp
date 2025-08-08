#include <bits/stdc++.h>
using namespace std;

class ThrowTheBall
{
public:
    int timesThrown(int N, int M, int L)
    {
        vector<int> p(N, 0);
        p[0]++;

        int i = 0; int count = 0;
        while (p[i] < M)
        {
            if(p[i] % 2 == 0){
                i =  (i + L) % N;
            }
            else{
                i = (i - L + N) % N;
            }
            count++;
            p[i]++;
        }
        return count;
    }
};