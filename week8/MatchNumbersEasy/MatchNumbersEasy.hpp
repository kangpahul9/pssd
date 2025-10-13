#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector <int> matches, int n)
 {
        long long maxNumber=0;
        long long currMax=0;
        long long left=n;
        for (int i = matches.size()-1; i >= 0; i--)
        {
            if (matches[i] > n) continue;
            left=n-matches[i];
            currMax=i;
            for (int j = matches.size()-1; j >= 0; j--)
            {
                int tempLeft = left;
                long long tempNum = currMax;
                while (tempLeft >= matches[j])
                {
                    tempNum=tempNum*10+j;
                maxNumber=max(tempNum,maxNumber);
                tempLeft-=matches[j];
                }
            }
        }
        string result = "";
        result=std::to_string(maxNumber);
        return result;
    }
};