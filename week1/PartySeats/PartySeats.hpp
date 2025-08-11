#include <bits/stdc++.h>
using namespace std;

class PartySeats {
public:
    vector<string> seating(vector<string> attendees) {
        vector<string> boys, girls, result;

        for (const string& s : attendees) {
            size_t pos = s.rfind(' ');

            string name = s.substr(0, pos);
            string gender = s.substr(pos + 1);

            if (gender == "boy") boys.push_back(name);
            else girls.push_back(name);
        }
        sort(boys.begin(), boys.end());
        sort(girls.begin(), girls.end());
        if (boys.size() != girls.size()) return {};
        if (girls.size() < 2) return {};

        result.push_back("HOST");

        int cb = 0, cg = 0;
        int total = attendees.size() + 2; 

        for (int i = 1; i < total; ++i) {
            if (i == total / 2) {              
                result.push_back("HOSTESS");
                continue;
            }
            if (i % 2 == 1) result.push_back(girls[cg++]); 
            else result.push_back(boys[cb++]);  
        }
        return result;
    }
};
