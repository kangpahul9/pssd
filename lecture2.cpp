#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class lottery
{

public:
    string payEqual(vector<int> notes, int price)
    {
        int sum = 0;
        for (int note : notes)
        {
            sum += note;
            if (note == price)
            {
                return "POSSIBLE";
            }
        }
        if (sum == price)
        {
            return "POSSIBLE";
        }
        if (sum - notes[0] == price || sum - notes[1] == price || sum - notes[2] == price || sum - notes[3] == price)
        {
            return "POSSIBLE";
        }
        if (notes[0] + notes[1] == price || notes[0] + notes[2] == price || notes[0] + notes[3] == price || notes[1] + notes[2] == price || notes[1] + notes[3] == price || notes[2] + notes[3] == price)
        {
            return "POSSIBLE";
        }
        return "IMPOSSIBLE";
    }
};

class BusSeatingMethod
{
private:
public:
     double getArrangement(string leftRow, string rightRow) {
        vector<pair<int,int>> emptySeats;
        for(int i=0;i<10;i++){
            if(leftRow[i]=='-') emptySeats.push_back({0,i});
            if(rightRow[i]=='-') emptySeats.push_back({2,i});
        }

        double minSum = 1e9;
        int n = emptySeats.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    auto [x1,y1]=emptySeats[i];
                    auto [x2,y2]=emptySeats[j];
                    auto [x3,y3]=emptySeats[k];

                    double sum = sqrt(pow(x1-x2,2)+pow(y1-y2,2))
                               + sqrt(pow(x1-x3,2)+pow(y1-y3,2))
                               + sqrt(pow(x2-x3,2)+pow(y2-y3,2));
                    minSum = min(minSum, sum);
                }
            }
        }
        return minSum;
    }
};

int main()
{
    lottery l;

    vector<vector<int>> testNotes = {
        {25, 10, 5, 1},
        {1, 2, 3, 4},
        {5, 5, 5, 5},
        {1, 2, 5, 7},
        {1000, 1000, 1000, 1000}};

    vector<int> prices = {30, 10, 15, 8, 5000};
    vector<string> expected = {"POSSIBLE", "POSSIBLE", "POSSIBLE", "POSSIBLE", "IMPOSSIBLE"};

    for (size_t i = 0; i < testNotes.size(); i++)
    {
        string result = l.payEqual(testNotes[i], prices[i]);
        cout << "Test case " << i << ": " << result
             << " (Expected: " << expected[i] << ")" << endl;
    }
    BusSeatingMethod bus;

    vector<pair<string, string>> busTestCases = {
        {"----------", "----------"},
        {"XXX-X-XX-X", "-XXXX--XX-"},
        {"XXXXXXXXXX", "-XX-XX-X--"},
        {"XXX-X-XX-X", "XXX-X-XX-X"}};

    vector<double> busExpected = {4.0, 4.0, 6.0, 6.82842712474619};

    cout << "\n--- Bus Seating Test Results ---" << endl;
    for (size_t i = 0; i < busTestCases.size(); i++)
    {
        double result = bus.getArrangement(busTestCases[i].first, busTestCases[i].second);
        cout << "Test case " << i << ": " << result
             << " (Expected: " << busExpected[i] << ")" << endl;
    }
    return 0;
}