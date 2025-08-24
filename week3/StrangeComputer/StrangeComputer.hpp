#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <climits>
using namespace std;

class StrangeComputer {
public:
    int setMemory(string mem) {
        int count = (mem[0] == '1') ? 1 : 0;
        for (int i = 1; i < mem.size(); i++) {
            if (mem[i] != mem[i - 1]) {
                count++;
            }
        }
        return count;
    }
};