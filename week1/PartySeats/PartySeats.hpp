#include <bits/stdc++.h>
using namespace std;
 
 
class PartySeats
{
  public:
  	String[] seating(String[] attendees)
 {
    vector<string> boys;
    vector<string> girls;
    vector <string> result;
    for (auto &i : attendees) {
        string name = i.substr(i.find(" "));
        string gender = i.substr(i.find(" ")+1);
        if(gender=="boy"){
        boys.push_back(name);}
        else{
            girls.push_back(name);
        }
    }
    sort(boys.begin(),boys.end());
    sort(girls.begin(),girls.end());
    if(boys.size() != girls.size()){ return result;}
    if(girls.size() < 2){ return result;}
    result.push_back("HOST"); int cb = 0; int cg = 0;
    for(int i = 1; i < attendees.size();i++){
        if(i == girls.size()+1){
            result.push_back("HOSTESS");
            continue;
        }
        if (i%2 == 0)
        {
            result.push_back(boys[cb]);
            cb++;
        }
        else
        {
            result.push_back(girls[cb]);
    }
};