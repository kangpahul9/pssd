#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Thimbles {
public:
    int thimbleWithBall(vector<string> swaps) {
        int ball = 1; 
        for (string s : swaps) {
            int a = s[0] - '0';
            int b = s[2] - '0';
            if (ball == a)
                ball = b;
            else if (ball == b)
                ball = a;
        }
        return ball;
    }
};