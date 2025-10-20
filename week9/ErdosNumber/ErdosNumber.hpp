#include <iostream>
#include <sstream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

class ErdosNumber {
public:
    vector<string> calculateNumbers(vector<string> publications) {
        vector<string> allAuthors;

        for (string pub : publications) {
            stringstream ss(pub);
            string name;
            while (ss >> name) {
                if (find(allAuthors.begin(), allAuthors.end(), name) == allAuthors.end())
                    allAuthors.push_back(name);
            }
        }

        sort(allAuthors.begin(), allAuthors.end());
        int n = allAuthors.size();

        auto getId = [&](const string &s) {
            return (int)(find(allAuthors.begin(), allAuthors.end(), s) - allAuthors.begin());
        };

        vector<vector<int>> g(n);
        for (string pub : publications) {
            vector<int> ids;
            stringstream ss(pub);
            string name;
            while (ss >> name) ids.push_back(getId(name));

            for (int i = 0; i < (int)ids.size(); i++)
                for (int j = i + 1; j < (int)ids.size(); j++) {
                    g[ids[i]].push_back(ids[j]);
                    g[ids[j]].push_back(ids[i]);
                }
        }

        vector<int> dist(n, -1);
        int erdosId = getId("ERDOS");
        dist[erdosId] = 0;
        queue<int> q;
        q.push(erdosId);

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : g[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }

        vector<string> res;
        for (int i = 0; i < n; i++) {
            if (dist[i] == -1) res.push_back(allAuthors[i]);
            else res.push_back(allAuthors[i] + " " + to_string(dist[i]));
        }

        return res;
    }
};
