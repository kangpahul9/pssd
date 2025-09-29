#include <bits/stdc++.h>
using namespace std;
class PrefixFreeSets
{
public:
    int maxElements(vector<string> words)
    {
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        int n = words.size();
        int result = 0;
        for (int i = 0; i < n; i++)
        {
            bool isPrefix = false;

            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if (words[j].size() >= words[i].size() &&
                    words[j].substr(0, words[i].size()) == words[i])
                {
                    isPrefix = true;
                    break;
                }
            }
            if (!isPrefix)
                result++;
        }
        return result;
    }
};