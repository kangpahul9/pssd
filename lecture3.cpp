#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class BootsExchange
{
public:
    int leastAmount(vector<int> left, vector<int> right){
        int n=left.size();
        vector<int>leftF(1001,0);
        vector<int>rightF(1001,0);
        int diff=0;

        for (int i = 0; i < left.size(); i++)
        {
           leftF[left[i]]++;
           rightF[right[i]]++;
        }
        for (int j = 0; j <= 1000; j++)
        {
            diff+=abs(leftF[j]-rightF[j]);
        }
        return diff/2;
    }
};

#include <iostream>
#include <vector>
using namespace std;

// Assume BootsExchange class with leastAmount is already implemented

int main() {
    BootsExchange shop;

    // Example 0
    vector<int> left0 = {1, 3, 1};
    vector<int> right0 = {2, 1, 3};
    cout << "Example 0: " << shop.leastAmount(left0, right0) << endl; // Expected: 1

    // Example 1
    vector<int> left1 = {1, 3};
    vector<int> right1 = {2, 2};
    cout << "Example 1: " << shop.leastAmount(left1, right1) << endl; // Expected: 2

    // Example 2
    vector<int> left2 = {1, 2, 3, 4, 5, 6, 7};
    vector<int> right2 = {2, 4, 6, 1, 3, 7, 5};
    cout << "Example 2: " << shop.leastAmount(left2, right2) << endl; // Expected: 0

    // You can add more test cases similarly
    return 0;
}




