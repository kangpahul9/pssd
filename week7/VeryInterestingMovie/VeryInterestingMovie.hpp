#include <bits/stdc++.h>
using namespace std;
class VeryInterestingMovie
{
public:
    int maximumPupils (vector <string> seats){
        int result = 0;
        for (string row : seats)
        {
            for (int i = 0; i < row.size(); i++)
            {
                if (row[i]=='Y')
                {
                    result++;
                    i++;
                }
            }
               
        }
        return result;
    }
};
