#include <bits/stdc++.h>
using namespace std;
class MinimalDifference
{
public:
    int digitSum(int num){
        int sum = 0;
        while (num > 0)
        {
            sum += num % 10;
            num = num/10;
        }
        return sum;
    }
  int findNumber(int A, int B, int C){
    int sumC = digitSum(C);int sumNum=0;int bestDiff = INT_MAX;int bestNum = INT_MAX;
    for (int i = A; i <=B; i++)
    {
        sumNum = digitSum(i);
        int diff = abs(sumNum - sumC);
        if (diff < bestDiff) {
                bestDiff = diff;
                bestNum = i;
            } else if (diff == bestDiff && i < bestNum) {
                // tie-breaker: smaller number
                bestNum = i;
            }
        }
        return bestNum;
    }
};