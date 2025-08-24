#include <iostream>
#include <vector>
#include <string>
#include <numeric>
using namespace std;

class AzimuthMonitoring {
public:
    int getAzimuth(vector<string> instructions) {
        int deg = 0;
        for (const string& instr : instructions) {
            if (instr == "HALT") break;

            if (instr == "TURN AROUND") {
                deg = (deg + 180) % 360;
            }
            else if (instr == "LEFT") {
                deg = (deg - 90 + 360) % 360;
            }
            else if (instr == "RIGHT") {
                deg = (deg + 90) % 360;
            }
            else if (instr.rfind("LEFT ", 0) == 0) {
                int x = stoi(instr.substr(5)); // after "LEFT "
                deg = (deg - x + 360) % 360;
            }
            else if (instr.rfind("RIGHT ", 0) == 0) {
                int x = stoi(instr.substr(6)); // after "RIGHT "
                deg = (deg + x) % 360;
            }
        }
        return deg;
    }
};