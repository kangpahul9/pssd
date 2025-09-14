#include <iostream>
using namespace std;

class BadSubstring
{
public:
    long howMany(int n)
    {
        return count(n, 3);
    }
     long count(int n, int prev)
    {
        if (n == 0) return 1; // empty string
        long res = 0;
        for (int next = 0; next < 3; ++next) // 0='a', 1='b', 2='c'
        {
            if (prev == 0 && next == 1) continue; // forbid "ab"
            res += count(n - 1, next);
        }
        return res;
    }
};

int main()
{
    BadSubstring solver;

    // Test cases
    cout << "n=0: " << solver.howMany(0) << " (Expected: 1)" << endl;
    cout << "n=1: " << solver.howMany(1) << " (Expected: 3)" << endl;
    cout << "n=2: " << solver.howMany(2) << " (Expected: 8)" << endl;
    cout << "n=3: " << solver.howMany(3) << " (Expected: 21)" << endl;
    cout << "n=4: " << solver.howMany(4) << " (Expected: 55)" << endl;
    cout << "n=5: " << solver.howMany(5) << " (Expected: 144)" << endl;

    return 0;
}
