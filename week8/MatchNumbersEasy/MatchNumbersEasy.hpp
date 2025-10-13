#include <iostream>
#include <vector>
#include <string>
using namespace std;

class MatchNumbersEasy {
public:
    string maxNumber(vector <int> matches, int n)
 {
                string maxNum = "0";

        for (int i = matches.size()-1; i >= 0; i--)
        {
            if (matches[i] > n) continue;
            int left = n - matches[i];
            string curr = to_string(i); 
            for (int j = matches.size()-1; j >= 0; j--)
            {
                 int tempLeft = left;
                string tempNum = curr;
                while (tempLeft >= matches[j]) {
                    tempNum += to_string(j);  
                    tempLeft -= matches[j];
                    if (isBigger(tempNum, maxNum))
                        maxNum = tempNum;
                }
            }
        }
        return maxNum;
    }
bool isBigger(const string &a, const string &b) {
        if (a.size() != b.size()) return a.size() > b.size();
        return a > b;
    }
};