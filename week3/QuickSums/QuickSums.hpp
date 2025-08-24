#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <climits>

using namespace std;

class QuickSums
{
public:
    int ans=INT_MAX;
    void dfs(const string &numbers, int index, int sum, int target, int additions, vector<int> &nums) {
        if (index == numbers.size()) {
            int currentSum = 0;
            for (int x : nums) currentSum += x;
            if (currentSum == target) {
                ans = min(ans, additions);
            }
            return;
        }

        string cur = "";
        for (int i = index; i < numbers.size(); i++) {
            cur += numbers[i];
            int val = stoi(cur);
            nums.push_back(val);
            dfs(numbers, i + 1, sum + val, target, (nums.size() - 1), nums);

            nums.pop_back(); 
        }
    }

    int minSums(string numbers, int sum)
    {
        ans = INT_MAX;
        vector<int> nums;
        dfs(numbers, 0, 0, sum, 0, nums);
        return (ans == INT_MAX) ? -1 : ans;
    }
};