#include <bits/stdc++.h>
using namespace std;
 
 
class StreetParking
{
  public:
  int freeParks(String street){
    int count = 0;
    int n = street.size();
    for(int i=0;i<n;i++){
        if(street[i]!='-'){
            continue;
        }
        if(i+1<n && street[i+1]=='B')
        {
            continue;
        }
        if(i-1>=0 && street[i-1]=='B'){
            continue;
        }
        if(i+1 < n && street[i+1]=='S'){
            continue;
        }
        if(i-1 >=0 && street[i-1]=='S'){
            continue;
        }
        count++;
    }
    return count;
  }
};