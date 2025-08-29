#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class RugSizes
{
public:
    int rugCount(int area)
    {
        int count = 0;int j=0;
        for (int i = 1; i*i <= area; i++)
        {
            if (area%i == 0)
            {
                j=area/i;
                if (i!=j && i%2 == 0 && j%2 ==0 )
                {
                    continue;
                }
                count++;
            }
        }
        return count;
    }
};