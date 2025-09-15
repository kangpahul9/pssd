#include <bits/stdc++.h>
using namespace std;
class PaternityTest

{
public:
    vector<int> possibleFathers(string child, string mother, vector<string> men)
    {
        vector<int> indices;
        int n = child.size();

        for (int i = 0; i < (int)men.size(); i++)
        {
            int fatherMatches = 0;
            bool isFather = true;

            for (int j = 0; j < n; j++)
            {
                if (child[j] == mother[j])
                {
                    if (child[j] == men[i][j])
                    {
                        fatherMatches++;
                    }
                }
                else
                {
                    if (child[j] == men[i][j])
                    {
                        fatherMatches++;
                    }
                    else
                    {
                        isFather = false;
                        break;
                    }
                }
            }

            if (isFather && fatherMatches >= n / 2)
            {
                indices.push_back(i);
            }
        }
        return indices;
    }
};
