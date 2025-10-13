#include <iostream>
#include <vector>
#include <string>
using namespace std;

class CorporationSalary {
public:
    long dfs(int i, vector<string>& rel, vector<long>& memo) {
        if (memo[i] != -1) return memo[i];

        long sum = 0;
        for (int j = 0; j < rel.size(); j++) {
            if (rel[i][j] == 'Y') {
                sum += dfs(j, rel, memo);
            }
        }

        if (sum == 0) sum = 1;

        return memo[i] = sum;
    }

    long totalSalary(vector<string> relations) {
        int n = relations.size();
        vector<long> memo(n, -1);

        long total = 0;
        for (int i = 0; i < n; i++) {
            total += dfs(i, relations, memo);
        }

        return total;
    }
};