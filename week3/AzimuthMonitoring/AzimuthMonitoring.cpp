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

int main() {
    AzimuthMonitoring A;

    cout << A.getAzimuth({"RIGHT"}) << "\n"; // 90
    cout << A.getAzimuth({"LEFT", "LEFT", "TURN AROUND"}) << "\n"; // 0
    cout << A.getAzimuth({"LEFT 5","RIGHT 10","LEFT 15","RIGHT 20","LEFT 25","RIGHT 30","LEFT 35","RIGHT 40"}) << "\n"; // 20
    cout << A.getAzimuth({"RIGHT 59","RIGHT","RIGHT","HALT","LEFT","LEFT","LEFT"}) << "\n"; // 239
    cout << A.getAzimuth({"TURN AROUND","HALT","LEFT 5","HALT","LEFT 5","HALT"}) << "\n"; // 180
    cout << A.getAzimuth({"LEFT","LEFT","LEFT","LEFT","LEFT","HALT"}) << "\n"; // 270
    return 0;
}