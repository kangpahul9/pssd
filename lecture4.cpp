#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


class Refactoring
{
private:
   

   
public:
    int refactor(int n){
    return dfs(n, 2);
}
    int dfs(int n, int minFactor){
        int count=0;
        for (long long f = minFactor; f * f <= n; f++) {
        if (n % f == 0) {
                count += 1 + dfs(n / f, f); // 1 for current factorization
            }
        }
        if (n >= minFactor) count += 0; // don't count n itself
    return count;
    }
    };


int main()
{
    Refactoring solver;

    // Example 0
    int n0 = 24;
    cout << "Test 0: " << solver.refactor(n0) << " (Expected: 6)" << endl;

    // Example 1
    int n1 = 9973;
    cout << "Test 1: " << solver.refactor(n1) << " (Expected: 0)" << endl;

    // Example 2
    int n2 = 9240;
    cout << "Test 2: " << solver.refactor(n2) << " (Expected: 295)" << endl;

    // Example 3
    int n3 = 1916006400;
    cout << "Test 3: " << solver.refactor(n3) << " (Expected: 7389115)" << endl;

    return 0;
}