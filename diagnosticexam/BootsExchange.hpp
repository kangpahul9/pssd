#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class BootsExchange {
public:
    int leastAmount(vector<int> left, vector<int> right) {
        unordered_map<int, int> leftCount, rightCount;

        for (int i : left) leftCount[i]++;
        for (int j : right) rightCount[j]++;

        for (auto &combo : leftCount) {
            int length = combo.first;
            int common = min(leftCount[length], rightCount[length]);
            leftCount[length] -= common;
            rightCount[length] -= common;
        }

        int exchanges = 0;
        for (auto &pair : leftCount) exchanges += pair.second;
        for (auto &pair : rightCount) exchanges += pair.second;

        return exchanges / 2;  // Each exchange fixes one left and one right
    }
};
