#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class ChangingString
{
public:
    int distance(string A, string B, int K)
    {
        int n = A.size();
        vector<int> distance(n, 0);
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            distance[i] = (int)(abs(A[i] - B[i]));
            sum += distance[i];
            if (distance[i] > 0)
                count++;
        }
        sort(distance.begin(), distance.end());
        if (K <= count)
        {
            for (int i = n - 1; i >= n - K; i--)
            {
                sum -= distance[i];
            }
            return sum;
        }
        return K - count;
    }
};

class DerivativeSequence
{
public:
    vector<int> derSeq(vector<int> a, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < a.size(); j++)
            {
                a[j] = a[j + 1] - a[j];
            }
            a.pop_back();
        }
        return a;
    }
};

void printVector(const vector<int> &v)
{
    cout << "{";
    for (size_t i = 0; i < v.size(); i++)
    {
        cout << v[i];
        if (i + 1 < v.size())
            cout << ", ";
    }
    cout << "}" << endl;
}

class AlternateColors
{
public:
    string getColor(long long r, long long g, long long b, long long k)
    {
        long long rounds = min({r, g, b}); // full rounds where all 3 colors exist
        long long ballsInFullRounds = 3 * rounds;

        if (k <= ballsInFullRounds)
        {
            // k-th ball is in the full rounds
            long long pos = (k - 1) % 3; // 0 = RED, 1 = GREEN, 2 = BLUE
            if (pos == 0)
                return "RED";
            if (pos == 1)
                return "GREEN";
            return "BLUE";
        }

        // Reduce r, g, b by the full rounds
        r -= rounds;
        g -= rounds;
        b -= rounds;
        k -= ballsInFullRounds; // remaining k

        // Now only colors with remaining balls matter
        // Loop through colors in order: RED, GREEN, BLUE
        while (true)
        {
            if (r > 0)
            {
                k--;
                if (k == 0)
                    return "RED";
                r--;
            }
            if (g > 0)
            {
                k--;
                if (k == 0)
                    return "GREEN";
                g--;
            }
            if (b > 0)
            {
                k--;
                if (k == 0)
                    return "BLUE";
                b--;
            }
        }
    }
};

class ElevatorLimit {
public:
    vector<int> getRange(vector<int> enter, vector<int> exit, int physicalLimit) {
        int n = enter.size();
        int minInit = 0; // minimum possible initial people
        int maxInit = physicalLimit; // maximum possible initial people

        int sumEnter = 0, sumExit = 0;

        for(int i = 0; i < n; i++) {
            sumEnter += enter[i];
            sumExit += exit[i];

            // minInit must be enough so curr people never go below 0
            minInit = max(minInit, sumExit - sumEnter);

            // maxInit must be small enough so curr people never exceed limit
            maxInit = min(maxInit, physicalLimit - (sumEnter - sumExit));
        }

        if(minInit > maxInit) return {}; // impossible
        return {minInit, maxInit};
    }
};

int main()
{
    ChangingString cs;

    vector<tuple<string, string, int, int>> testCases = {
        {"ab", "ba", 2, 0},
        {"aa", "aa", 2, 2},
        {"aaa", "baz", 1, 1},
        {"fdfdfdfdfdsfabasd", "jhlakfjdklsakdjfk", 8, 24},
        {"aa", "bb", 2, 0}};

    for (size_t i = 0; i < testCases.size(); i++)
    {
        auto [A, B, K, expected] = testCases[i];
        int result = cs.distance(A, B, K);
        cout << "Test case " << i << ": " << result
             << " (Expected: " << expected << ")" << endl;
    }

    DerivativeSequence ds;

    // Test case 0
    vector<int> a0 = {5, 6, 3, 9, -1};
    int n0 = 1;
    printVector(ds.derSeq(a0, n0)); // Expected: {1, -3, 6, -10}

    // Test case 1
    vector<int> a1 = {5, 6, 3, 9, -1};
    int n1 = 2;
    printVector(ds.derSeq(a1, n1)); // Expected: {-4, 9, -16}

    // Test case 2
    vector<int> a2 = {5, 6, 3, 9, -1};
    int n2 = 4;
    printVector(ds.derSeq(a2, n2)); // Expected: {-38}

    // Test case 3
    vector<int> a3 = {4, 4, 4, 4, 4, 4, 4, 4};
    int n3 = 3;
    printVector(ds.derSeq(a3, n3)); // Expected: {0,0,0,0,0}

    // Test case 4
    vector<int> a4 = {-100, 100};
    int n4 = 0;
    printVector(ds.derSeq(a4, n4)); // Expected: {-100, 100}

    // Edge case: single element
    vector<int> a5 = {42};
    int n5 = 0;
    printVector(ds.derSeq(a5, n5)); // Expected: {42}

    // Increasing sequence
    vector<int> a6 = {1, 2, 3, 4, 5};
    int n6 = 2;
    printVector(ds.derSeq(a6, n6)); // Expected: {0,0,0}

    // Alternating sequence
    vector<int> a7 = {1, -1, 1, -1, 1};
    int n7 = 2;
    printVector(ds.derSeq(a7, n7)); // Expected: {4,-4,4}

    AlternateColors ac;
    cout << ac.getColor(1, 1, 1, 3) << endl;                             // BLUE
    cout << ac.getColor(3, 4, 5, 4) << endl;                             // RED
    cout << ac.getColor(7, 7, 1, 7) << endl;                             // GREEN
    cout << ac.getColor(653, 32, 1230, 556) << endl;                     // BLUE

    ElevatorLimit elevator;

    // Example 0
    vector<int> enter0 = {1, 0};
    vector<int> exit0 = {0, 1};
    int physicalLimit0 = 1;
    vector<int> result0 = elevator.getRange(enter0, exit0, physicalLimit0);
    for (int x : result0)
        cout << x << " ";
    cout << endl; // Expected: 0 0

    // Example 1
    vector<int> enter1 = {1, 0};
    vector<int> exit1 = {0, 1};
    int physicalLimit1 = 2;
    vector<int> result1 = elevator.getRange(enter1, exit1, physicalLimit1);
    for (int x : result1)
        cout << x << " ";
    cout << endl; // Expected: 0 1

    // Example 2
    vector<int> enter2 = {0, 1};
    vector<int> exit2 = {1, 0};
    int physicalLimit2 = 1;
    vector<int> result2 = elevator.getRange(enter2, exit2, physicalLimit2);
    for (int x : result2)
        cout << x << " ";
    cout << endl; // Expected: 1 1

    // Example 3 (impossible)
    vector<int> enter3 = {0, 2};
    vector<int> exit3 = {1, 0};
    int physicalLimit3 = 1;
    vector<int> result3 = elevator.getRange(enter3, exit3, physicalLimit3);
    if (result3.empty())
        cout << "Impossible" << endl; // Expected: Impossible

    return 0;
}