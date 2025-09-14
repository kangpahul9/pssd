#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class DerivativeSequence
{
public:
    vector<int> derSeq(vector<int> a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a.size(); j++)
            {
                a[j] = a[j + 1] - a[j];
            }
            a.pop_back();
        }
        return a;
    }
};
