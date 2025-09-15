#include <bits/stdc++.h>
using namespace std;
class FewestFactors
{
public:
    int numberOfFactors(int num)
    {
        int count;
        for (int i = 0; i < num / 2; i++)
        {
            if (num % i == 0)
            {
                count++;
            }
        }
        return count;
    }
    int number(vector<int> digits)
    {
        sort(digits.begin(), digits.end());
        int bestNum;
        int bestFactors;

        do
        {
            int num = 0;
            for (int d : digits)
            {
                num = num * 10 + d;
            }

            int f = numberOfFactors(num);
            if (f < bestFactors || (f == bestFactors && num < bestNum))
            {
                bestFactors = f;
                bestNum = num;
            }
        } while (next_permutation(digits.begin(), digits.end()));

        return bestNum;
    }
};