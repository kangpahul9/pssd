#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Arrows
{
public:
    int longestArrow(string s)
    {
        int n = s.size();
        int best = -1;

        for (int i = 0; i < n; i++)
        {
            if (s[i] == '<')
            {
                // Left single arrow "<-..."
                int len = 1;
                int j = i + 1;
                while (j < n && s[j] == '-')
                {
                    len++;
                    j++;
                }
                best = max(best, len);

                // Left double arrow "<=..."
                len = 1;
                j = i + 1;
                while (j < n && s[j] == '=')
                {
                    len++;
                    j++;
                }
                best = max(best, len);
            }
            else if (s[i] == '>')
            {
                // Right single arrow "...->"
                int len = 1;
                int j = i - 1;
                while (j >= 0 && s[j] == '-')
                {
                    len++;
                    j--;
                }
                best = max(best, len);

                // Right double arrow "...=>"
                len = 1;
                j = i - 1;
                while (j >= 0 && s[j] == '=')
                {
                    len++;
                    j--;
                }
                best = max(best, len);
            }
        }
        return best;
    }
};

class QuickSums
{
public:
    int minSums(string numbers, int sum)
    {
        int ans = dfs(numbers, 0, sum);
        return (ans >= INT_MAX / 2) ? -1 : ans;
    }
    int dfs(string s, int idx, int target)
    {
        if (idx == s.size())
        {
            return (target == 0 ? 0 : INT_MAX / 2);
        }
        int res = INT_MAX / 2;
        long long num = 0;
        for (int i = idx; i < s.size(); i++)
        {
            num = num * 10 + (s[i] - '0');
            if (num > target)
                break;
            int next = dfs(s, i + 1, target - num);
            if (next != INT_MAX / 2)
            {
                // if not at last cut, we need +1 addition
                if (i + 1 < s.size())
                    res = min(res, 1 + next);
                else
                    res = min(res, next);
            }
        }
        return res;
    }
};

class SimpleCompressor
{
public:
    string uncompress(string data)
    {
        int i = 0;
        return recursion(data, i);
        ;
    }
    string recursion(const string &data, int &i)
    {
        string result = "";
        int n = data.size();

        while (i < n && data[i] != ']')
        {
            if (isalpha(data[i]))
            {
                // normal letter
                result += data[i];
                i++;
            }
            else if (data[i] == '[')
            {
                // enter bracket
                i++;
                int repeat = data[i] - '0';         // single digit guaranteed
                i++;                                // move past digit
                string inside = recursion(data, i); // expand inside
                i++;                                // skip ']'
                for (int k = 0; k < repeat; k++)
                {
                    result += inside;
                }
            }
            else
            {
                i++; // safety skip
            }
        }

        return result;
    }
};

class FewestFactors
{
private:
   int numberOfFactors(int number){
    int count;
    for (int i = 0; i < number/2; i++)
    {
        if (number%i==0)
        {
            count++;
        }
        
    }
    return count;
   }

   
public:
    int number(vector<int> digits) {
        sort(digits.begin(), digits.end()); // for next_permutation
        int bestNum = INT_MAX;
        int bestFactors = INT_MAX;

        do {
            int num = 0;
            for (int d : digits) {
                num = num * 10 + d;
            }

            int f = numberOfFactors(num);
            if (f < bestFactors || (f == bestFactors && num < bestNum)) {
                bestFactors = f;
                bestNum = num;
            }
        } while (next_permutation(digits.begin(), digits.end()));

        return bestNum;
    }
};



int main()
{
    Arrows s;

    // Test Arrows
    cout << "Arrows Tests:" << endl;
    cout << "Test 0: " << s.longestArrow("<--->--==>") << " (Expected: 4)" << endl;
    cout << "Test 1: " << s.longestArrow("<<<<<<<<<<") << " (Expected: 1)" << endl;
    cout << "Test 2: " << s.longestArrow("----==-") << " (Expected: -1)" << endl;
    cout << "Test 3: " << s.longestArrow("<----=====>") << " (Expected: 6)" << endl;

    QuickSums qs;

    // Test QuickSums
    cout << "\nQuickSums Tests:" << endl;
    cout << "Test 0: " << qs.minSums("99999", 45) << " (Expected: 4)" << endl;
    cout << "Test 1: " << qs.minSums("1110", 3) << " (Expected: 3)" << endl;
    cout << "Test 2: " << qs.minSums("0123456789", 45) << " (Expected: 8)" << endl;
    cout << "Test 3: " << qs.minSums("99999", 100) << " (Expected: -1)" << endl;
    cout << "Test 4: " << qs.minSums("382834", 100) << " (Expected: 2)" << endl;
    cout << "Test 5: " << qs.minSums("9230560001", 71) << " (Expected: 4)" << endl;

    SimpleCompressor sc;

    cout << sc.uncompress("C[6AB]C") << endl;               // CABABABABABABC
    cout << sc.uncompress("C[2[3AB]]C") << endl;            // CABABABABABABC
    cout << sc.uncompress("CO[1N]TEST") << endl;            // CONTEST
    cout << sc.uncompress("[2[2AB]]") << endl;              // ABABABAB
    cout << sc.uncompress("AAAAAAAAAAAAAAAAAAAAA") << endl; // AAAAAAAAAAAAAAAAAAAAA

    FewestFactors solver;

    vector<int> test0 = {1, 2};
    cout << "Test 0: " << solver.number(test0) << " (Expected: 21)" << endl;

    vector<int> test1 = {6, 0};
    cout << "Test 1: " << solver.number(test1) << " (Expected: 6)" << endl;

    vector<int> test2 = {4, 7, 4};
    cout << "Test 2: " << solver.number(test2) << " (Expected: 447)" << endl;

    vector<int> test3 = {1, 3, 7, 9};
    cout << "Test 3: " << solver.number(test3) << " (Expected: 1973)" << endl;

    vector<int> test4 = {7, 5, 4, 3, 6};
    cout << "Test 4: " << solver.number(test4) << " (Expected: 36457)" << endl;

    vector<int> test5 = {1, 2, 4};
    cout << "Test 5: " << solver.number(test5) << " (Expected: 241)" << endl;

    return 0;
}