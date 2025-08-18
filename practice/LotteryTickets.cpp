#include <string>   
#include <iostream>
using namespace std;
class LotteryTickets
{

public:
    string payCash(int b1,int b2,int b3,int b4, int price ){
        int S = b1 + b2 + b3 + b4;
        if (S < price)
        {
            return "IMPOSSIBLE";
        }
        if (price == S)
        {
            return "POSSIBLE";
        }
        if (S-b1 == price || S-b2 == price || S-b3 == price || S-b4 == price)
        {
            return "POSSIBLE";
        }
        if (b1+b2 == price || b1+b3 == price ||
            b1+b4 == price || b2+b3 == price ||
            b2+b4 == price || b3+b4 == price)
        {
            return "POSSIBLE";
        }
        if(b1 == price || b2 == price || b3 == price || b4 == price)
        {
            return "POSSIBLE";
        }
        return "IMPOSSIBLE";
    }
};

int main() {
    LotteryTickets lt;
    int price, b1, b2, b3, b4;

    // cout << "Enter price and 4 banknotes: ";
    // cin >> price >> b1 >> b2 >> b3 >> b4;

    // cout << lt.payCash(b1, b2, b3, b4, price) << endl;

    // Example quick tests
    cout << lt.payCash(10, 20, 30, 40, 50) << " (expected POSSIBLE)" << endl;
    cout << lt.payCash(1, 2, 3, 4, 15) << " (expected IMPOSSIBLE)" << endl;
    cout << lt.payCash(1, 1, 1, 1, 4) << " (expected POSSIBLE)" << endl;
    cout << lt.payCash(5, 1, 1, 1, 1) << " (expected POSSIBLE)" << endl;

    return 0;
}
