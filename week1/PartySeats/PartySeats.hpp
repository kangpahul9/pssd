#include <bits/stdc++.h>
using namespace std;

class PartySeats
{
public:
    vector<string> seating(vector<string> attendees)
    {
        vector<string> boys;
        vector<string> girls;
        vector<string> result; string pos= " ";
        for (auto &i : attendees)
        {
            string name = i.substr(0, pos);
            string gender = i.substr(pos + 1);
            if (gender == "boy")
            {
                boys.push_back(name);
            }
            else
            {
                girls.push_back(name);
            }
        }
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());
        if (boys.size() != girls.size())
        {
            return result;
        }
        if (girls.size() < 2)
        {
            return result;
        }
        result.push_back("HOST");
        int cb = 0;
        int cg = 0;
        for (int i = 1; i < attendees.size(); i++)
        {
            if (i == attendees.size()/ 2)
            {
                result.push_back("HOSTESS");
                continue;
            }
            if (i % 2 == 0)
            {
                result.push_back(boys[cb]);
                cb++;
            }
            else
            {
                result.push_back(girls[cg]);
                cg++;
            }
        }
        return result;
    }
};