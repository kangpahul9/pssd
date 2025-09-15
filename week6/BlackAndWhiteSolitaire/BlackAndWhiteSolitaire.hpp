#include <bits/stdc++.h>
using namespace std;
class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        int n=cardFront.size();
        int countBcorrect=0;
        int countWcorrect=0;
        char correctB,correctW;
        if (cardFront[0]=='B')
        {
            for (int i = 0; i < n-1; i++)
        {
            if (cardFront[i]=='B'&&i%2==0)
            {
                countBcorrect++;
            }
        }
        }
        
        if (cardFront[0]=='W')
        {
            for (int i = 0; i < n-1; i++)
        {
            if (cardFront[i]=='W'&&i%2==0)
            {
                countWcorrect++;
            }
        }
        }
        return min(countBcorrect,countWcorrect);
    }
};