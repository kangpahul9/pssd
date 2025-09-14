#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Barbecue
{
public:
    int eliminate(int n, vector<int> voter, vector<int> excluded)
    {
        vector<int> votesBy(n, 0);
        vector<int> votesFor(n, 0);
        int maxValue = 0, maxIndex = 0;

        for (int i = 0; i < voter.size(); i++)
        {
            votesBy[voter[i]]++;
            votesFor[excluded[i]]++;
        }
        for (int i = 0; i < n; i++)
        {
            if (votesFor[i] > maxValue)
            {
                maxValue = votesFor[i];
                maxIndex = i;
            }
            else if (votesFor[i] == maxValue)
            {
                if (votesBy[i] > votesBy[maxIndex])
                {
                    maxValue = votesFor[i];
                    maxIndex = i;
                }
                else if (votesBy[i] == votesBy[maxIndex])
                {
                    if (i < maxIndex)
                    {
                        maxValue = votesFor[i];
                        maxIndex = i;
                    }
                    else
                    {
                        continue;
                    }
                }
                else
                {
                    continue;
                }
            }
        }
        return maxIndex;
    }
};

class RunLengthEncoding
{
public:
    string decode(string text){
        int n=text.size();
        string result;
        int sum=0;int i = 0;
        while (i<n) 
        {
            int count = 0;
            while (i < n && isdigit(text[i])) {
                count = count * 10 + (text[i] - '0');
                i++;
            }
                        if (count == 0) count = 1;
            if (i < n && isupper(text[i])) {
                char letter = text[i++];
                // Append 'count' copies of letter
                if (result.size() + count > 50) {
                    return "TOO LONG";
                }
                result.append(count, letter);
            }
        }
        return result;
    }
};

class SimpleDuplicateRemover
{
public:
    vector <int> process( vector <int> sequence){
        int n=sequence.size();
         vector<int> lastIndex(1001, -1);
         vector<int>result;
        for (int i = 0; i < n; i++)
            lastIndex[sequence[i]] = i;
        for (int i = 0; i < n; i++)
        {
            if (lastIndex[sequence[i]] == i)
                result.push_back(sequence[i]); // only keep rightmost occurrence
        }
        return result;
    }
};


int main() {
    RunLengthEncoding rle;
    cout << rle.decode("4A3BC2DE") << " (Expected: AAAABBBCDDE)" << endl;
    cout << rle.decode("1A1B1C1D1E") << " (Expected: ABCDE)" << endl;
    cout << rle.decode("1A3A5A4BCCCC") << " (Expected: AAAAAAAAABBBBCCCC)" << endl;
    cout << rle.decode("50A") << " (Expected: 50 A's)" << endl;
    cout << rle.decode("21Z13S9A8M") << " (Expected: TOO LONG)" << endl;
    cout << rle.decode("123456789012345678901234567890B") << " (Expected: TOO LONG)" << endl;
    SimpleDuplicateRemover sdr;
    vector<int> v = {1, 5, 5, 1, 6, 1};
    vector<int> res = sdr.process(v);

    for (int x : res)
        cout << x << " ";
    cout << endl; // Output: 5 6 1
    return 0;
}
