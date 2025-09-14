#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class EmoticonsDiv2
{
public:
    int printSmiles(int smiles) {
        int res = 0;
        int n = smiles;
        for (int i = 2; i <= n; i++) {
            while (n % i == 0) {
                res += i;  // copy + paste steps
                n /= i;
            }
        }
        return res;
    }
};

int main() {
    EmoticonsDiv2 ed;
    cout << ed.printSmiles(2) << " (Expected: 2)" << endl;
    cout << ed.printSmiles(6) << " (Expected: 5)" << endl;
    cout << ed.printSmiles(11) << " (Expected: 11)" << endl;
    cout << ed.printSmiles(16) << " (Expected: 8)" << endl;
    cout << ed.printSmiles(1000) << " (Expected: 21)" << endl;
    return 0;
}