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
        int count = 0;
        for (int i = 1; i <= area; i++)
        {
            for (int j = 1; j <= area/2; j++)
            {
                if (i * j == area && (i%2==0 && j%2==0))
                {
                    count++;
                }
            }
            
        }
        return count;
    }
};