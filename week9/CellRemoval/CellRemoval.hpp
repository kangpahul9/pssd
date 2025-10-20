#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class CellRemoval {
public:
    int cellsLeft(vector<int> parent, int deletedCell) {
        int n = parent.size();
        vector<vector<int>> children(n);

        int root = -1;
        for (int i = 0; i < n; i++) {
            if (parent[i] == -1) root = i;
            else children[parent[i]].push_back(i);
        }

        vector<bool> deleted(n, false);
        dDelete(children, deleted, deletedCell);

        if (deleted[root]) return 0;

        int countLeaves = 0;
        for (int i = 0; i < n; i++) {
            if (deleted[i]) continue;
            bool hasChild = false;
            for (int child : children[i]) {
                if (!deleted[child]) {
                    hasChild = true;
                    break;
                }
            }
            if (!hasChild) countLeaves++;
        }

        return countLeaves;
    }

    void dDelete(vector<vector<int>> &children, vector<bool> &deleted, int node) {
        deleted[node] = true;
        for (int c : children[node])
            dDelete(children, deleted, c);
    }
};
