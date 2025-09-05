#include<bits/stdc++.h>
using namespace std;

class RunLengthEncoding
{    
public:
    string decode(string text){
        int n=text.size();
        char c;
        vector<char>characters;
        vector<int>numbers; int currNumber=0,sum=0;
        string result;

        for (int i = 0; i < n; i++)
        {
            c=text[i];
            if ((int)c>=65)
            {
                characters.push_back(c);
                if (currNumber==0)
                {
                    numbers.push_back(1);
                }
                else{
                    numbers.push_back(currNumber);
                }
                currNumber=0;
                sum+=numbers.back();
            }
            else{
                currNumber=currNumber*10 + (c-'0');
            }
            if (sum > 50)
            {
               return "TOO LONG";
            }
        }

        for (int i = 0; i < numbers.size(); i++)
        {
            for (int j = 0; j < numbers[i]; j++)
            {
                result.push_back(characters[i]);
            }
        }
        return result;
    }
};
