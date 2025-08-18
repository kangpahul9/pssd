#include <bits/stdc++.h>
using namespace std;
 
 
class ChangingString
{
  public:
  int distance(vector<string> A, vector<string> B, int K) {
    vector<int> d;
    int nonZero,sum=0;
    for (int i = 0; i < A.size(); i++)
    {
        di[i]= abs(A[i].size() - B[i].size());
        sum += di[i];
        if (di[i] > 0) nonZero++;
    }
    
    if(K <=nonZero) {
         for (int i = A.size() - 1; i >= A.size() - K; --i)
         {sum -= d[i];}
            return sum;
    }
    else return K-nonZero;
  }
};