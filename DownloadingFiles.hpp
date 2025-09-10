#include <iostream>
#include <vector>
#include <string>

using namespace std;
class DownloadingFiles {
public:
    double actualTime(vector<string> tasks){
        double totalTime =0.0; 
        vector<double> downloadSpeed(tasks.size(), 0.0); 
        vector<double> downloadTimes(tasks.size(), 0.0);
        double bandwidth = 0.0;
        double totalSize = 0.0;
        for (int i=0; i < tasks.size(); ++i) {
            size_t pos = tasks[i].find(' ');
            downloadSpeed[i] = stod(tasks[i].substr(0, pos));
            downloadTimes[i] = stod(tasks[i].substr(pos+1));
            bandwidth += downloadSpeed[i];
            int size = downloadSpeed[i] * downloadTimes[i];
            totalSize += size;
        }
        return totalSize/bandwidth;
    }
};

            