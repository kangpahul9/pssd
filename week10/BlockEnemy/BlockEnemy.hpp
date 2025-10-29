#include <vector>
#include<vector>
#include<utility>
#include <algorithm>
#include <sstream>
using namespace std;
class BlockEnemy
{
    
public:
    int N;
    vector<vector<pair<int,int>>> adj;
    vector<int>occupied;
    int totalOccupied;
    int ans;
    int dfs(int node, int parent) {
        int count = occupied[node];
        for (auto [nei, cost] : adj[node]) {
            if (nei == parent) continue;
            int sub = dfs(nei, node);
            if (sub > 0 && sub < totalOccupied) {
                ans += cost;
            }
            count += sub;
        }
        return count;
    }
   	int minEffort(int N, vector<string> roads, vector <int> occupiedTowns){
        this->N=N;
        ans = 0; 
        adj.assign(N,{});
        occupied.assign(N,0);
        for (int t : occupiedTowns)
            occupied[t] = 1;
        totalOccupied = occupiedTowns.size();
        for (string s : roads)
        {
            stringstream ss(s);
            int a, b, e;
            ss >> a >> b >> e;
            adj[a].push_back({b, e});
            adj[b].push_back({a, e});
        }
        dfs(0, -1);
        return ans;
    }
};
