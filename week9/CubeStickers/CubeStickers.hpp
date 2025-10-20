#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

class CubeStickers {
public:
    string isPossible(vector<string> sticker) {
        map<string,int> cnt;
        for (auto &s : sticker) cnt[s]++;
        
        int c1 = 0, c2 = 0;
        for (auto &p : cnt) {
            if (p.second >= 1) c1++;
            if (p.second >= 2) c2++;
        }

        return (c1 + c2 >= 6) ? "YES" : "NO";
    }
};
