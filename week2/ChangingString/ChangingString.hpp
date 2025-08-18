#include <bits/stdc++.h>
using namespace std;
 
 
class ChangingString
{
  public:
  int distance(string A, string B, int K) {
    vector<int> di(A.size());
    int nonZero=0;int sum=0;
    for (int i = 0; i < A.size(); i++)
    {
        di[i]= abs((int)A[i] - (int)B[i]);
        sum += di[i];
        if (di[i] > 0) nonZero++;
    }
    sort(di.begin(), di.end());
    
    if(K <=nonZero) {
         for (int i = A.size() - 1; i >= A.size() - K; --i)
         {sum -= di[i];}
            return sum;
    }
    else return K-nonZero;
  }
};