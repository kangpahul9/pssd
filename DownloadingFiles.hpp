//Gemini's code
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

class DownloadingFiles {
public:
    double actualTime(std::vector<std::string> tasks) {
        double totalData = 0.0;
        double totalSpeed = 0.0;

        for (const auto& task : tasks) {
            std::stringstream ss(task);
            int speed, time;
            ss >> speed >> time;

            totalData += static_cast<double>(speed) * time;
            totalSpeed += static_cast<double>(speed);
        }

        return totalData / totalSpeed;
    }
};