#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class FewestFactors
{
private:
   int numberOfFactors(int number){
    int count;
    for (int i = 0; i < number/2; i++)
    {
        if (number%i==0)
        {
            count++;
        }
        
    }
    return count;
   }

   
public:
    int number(vector<int> digits) {
        sort(digits.begin(), digits.end()); // for next_permutation
        int bestNum = INT_MAX;
        int bestFactors = INT_MAX;

        do {
            int num = 0;
            for (int d : digits) {
                num = num * 10 + d;
            }

            int f = numberOfFactors(num);
            if (f < bestFactors || (f == bestFactors && num < bestNum)) {
                bestFactors = f;
                bestNum = num;
            }
        } while (next_permutation(digits.begin(), digits.end()));

        return bestNum;
    }
};