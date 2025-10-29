#include <vector>
#include <algorithm>
using namespace std;

class BigBurger {
public:
    int maxWait(vector<int> arrival, vector<int> service) {
        int n = arrival.size();
        int currentTime = 0; 
        int maxWait = 0;

        for (int i = 0; i < n; i++) {
            if (arrival[i] > currentTime) {
                currentTime = arrival[i];
            }
            int wait = currentTime - arrival[i];
            maxWait = max(maxWait, wait);
            currentTime += service[i];
        }

        return maxWait;
    }
};
