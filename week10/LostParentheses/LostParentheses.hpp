#include <string>
#include <sstream>
#include <vector>
using namespace std;

class LostParentheses {
public:
    int minResult(string e) {
        vector<int> groupSums;
        stringstream ss(e);
        string part;
        
        while (getline(ss, part, '-')) {
            int sum = 0;
            stringstream sub(part);
            string num;
            while (getline(sub, num, '+')) {
                sum += stoi(num);
            }
            groupSums.push_back(sum);
        }

        int result = groupSums[0];
        for (int i = 1; i < (int)groupSums.size(); i++) {
            result -= groupSums[i];
        }

        return result;
    }
};
