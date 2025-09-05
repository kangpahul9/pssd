#include<bits/stdc++.h>
using namespace std;

class Multiples
{    
public:
    int number(int min, int max, int factor){
        int count = 0;
        for (int i = min; i <=max; i++)
        {
           if (i%factor==0)
           {
            count++;
           }
        }
     return count;   
    }
};
