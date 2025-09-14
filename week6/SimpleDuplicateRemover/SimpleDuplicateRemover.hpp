#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class SimpleDuplicateRemover
{
public:
    vector <int> process( vector <int> sequence){
        int n=sequence.size();
         vector<int> lastIndex(1001, -1);
         vector<int>result;
        for (int i = 0; i < n; i++)
            lastIndex[sequence[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (lastIndex[sequence[i]] == i)
                result.push_back(sequence[i]); 
        }
        return result;
    }
};