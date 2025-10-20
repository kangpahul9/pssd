#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class CatGame
{
public:
    int getNumber(vector<int> coordinates, int X) {
    sort(coordinates.begin(), coordinates.end());
    int n = coordinates.size();
    int ans = INT_MAX;

    for (int i = -1; i < n; i++) {
        int leftmost, rightmost;

        if (i == -1) {
            // all move left
            leftmost = coordinates[0] - X;
            rightmost = coordinates[n-1] - X;
        } else if (i == n - 1) {
            // all move right
            leftmost = coordinates[0] + X;
            rightmost = coordinates[n-1] + X;
        } else {
            // split: [0..i] right, [i+1..n-1] left
            leftmost = min(coordinates[0] + X, coordinates[i+1] - X);
            rightmost = max(coordinates[i] + X, coordinates[n-1] - X);
        }

        ans = min(ans, rightmost - leftmost);
    }

    return ans;
}
};



