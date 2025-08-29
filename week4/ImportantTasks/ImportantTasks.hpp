#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class ImportantTasks
{
public:
    int maximalCost(vector<int> &complexity, vector<int> &computers)
    {
        int count = 0;
        sort(complexity.begin(), complexity.end());
        sort(computers.begin(), computers.end());
        int i=0, j=0;
        while (i < complexity.size() && j < computers.size())
        {
            if (computers[j] >= complexity[i])
            {
                count ++;
                i++;
                j++;
            }
            else
            {
                j++;
            }
        }
        
        
        return count;
    }
};