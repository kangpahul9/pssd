#include <iostream>
#include <algorithm>
using namespace std;

class RockStar {
public:
    int getNumSongs(int ff, int fs, int sf, int ss) {
        if (ff + fs == 0) {
            return ss + (sf > 0 ? 1 : 0);
        }

        if (fs == 0) {
            return ff;
        }

        int ans = ff;                
        ans += 1;                     
        ans += ss;                    
        ans += 2 * min(sf, fs - 1);  
        if (sf >= fs) ans += 1;      
        return ans;
    }
};
