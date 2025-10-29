#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BridgeSort {
public:
    string sortedHand(string hand) {
    string suites = "CDHS";
    string values = "23456789TJQKA";
    vector<string> eachSuite[4];
    for (size_t i = 0; i < hand.size(); i+=2)
    {
        string card = hand.substr(i,2);
        char c=card[0];
        int index = suites.find(c);
        eachSuite[index].push_back(card);
    }
    for (int i = 0; i < 4; i++)
    {
        sort(eachSuite[i].begin(),eachSuite[i].end(), [&](string a, string b){return values.find(a[1])<values.find(b[1]);});
    }
    string result = "";
        for (int i = 0; i < 4; i++) {
            for (string card : eachSuite[i])
                result += card;
        }
    return result;
    }
};