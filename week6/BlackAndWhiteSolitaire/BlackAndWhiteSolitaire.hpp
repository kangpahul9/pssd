#include <bits/stdc++.h>
using namespace std;
class BlackAndWhiteSolitaire {
public:
    int minimumTurns(string cardFront) {
        int n=cardFront.size();
        int countBcorrect=0;
        int countWcorrect=0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) { 
                if (cardFront[i] != 'B') countBcorrect++;
                if (cardFront[i] != 'W') countWcorrect++;
            } else { 
                if (cardFront[i] != 'W') countBcorrect++;
                if (cardFront[i] != 'B') countWcorrect++;
            }
        }
        return min(countBcorrect,countWcorrect);
    }
};