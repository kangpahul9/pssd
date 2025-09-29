#include <bits/stdc++.h>
using namespace std;
class PrefixFreeSets
{
public:
    int maxElements(vector<string> words){
        int n=words.size();
        int result=n;string word;
        for (int i = 0; i < n; i++)
        {
            string word = words[i];
            for (int j = 0; j < n; j++)
            {
                if (i==j)
                {
                    continue;
                }
                if (words[j].find(word) != std::string::npos )
                {
                    result--;
                }
            }
        }
        return result;
        
    }

};