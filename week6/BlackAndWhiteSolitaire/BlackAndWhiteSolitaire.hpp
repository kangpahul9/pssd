#include <bits/stdc++.h>
using namespace std;
class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        int n=cardFront.size();
        int count=0;
       
        for (int i = 0; i < n-1; i++)
        {
            if (cardFront[i]==cardFront[i+1])
            {
                count++;
            }
        }
        return count%2==0 ? count/2 : count/2+1;
    }
};