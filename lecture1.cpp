#include <iostream>
#include <vector>
#include <string>
using namespace std;

class AimToTen{
    public:
    int need(vector<int> marks){
        int sum=0;int n=marks.size();
        for (auto mark : marks)
        {
           sum+=mark;
        }
        double avg=sum/n;
        if (avg >=9.5)
        {
            return 0;
        }
        return 2*(9.5*n - sum);
    }
};

class FunnyFence{
    public:
    int getLength(string s){
        int count=1;int maxCount=0;
        int n=s.size();
        for(int i=0;i<n-1;i++){
            if (s[i]==s[i+1])
            {
                maxCount=max(maxCount,count);
                count=1;
            }
            else{
            count++;
            }
        }
        return max(maxCount,count);
    }
};

int main() {
    AimToTen a;
    FunnyFence f;

    // Problem 1 tests
    cout << "AimToTen Tests:" << endl;
    cout << a.need({9, 10, 10, 9}) << " (Expected 0)" << endl;
    cout << a.need({8, 9}) << " (Expected 4)" << endl;
    cout << a.need(vector<int>(50, 0)) << " (Expected 950)" << endl;
    cout << a.need({10, 10, 10, 10}) << " (Expected 0)" << endl;

    // Problem 2 tests
    cout << "\nFunnyFence Tests:" << endl;
    cout << f.getLength("|-|-|") << " (Expected 5)" << endl;
    cout << f.getLength("-|-|-|-") << " (Expected 7)" << endl;
    cout << f.getLength("||||||") << " (Expected 1)" << endl;
    cout << f.getLength("|-||-|-") << " (Expected 4)" << endl;
    cout << f.getLength("|-|----|-|----|-|") << " (Expected 5)" << endl;
    cout << f.getLength("|||-||---|----|----|----||-|-|-|----||---||-||-||-|----||") << " (Expected 8)" << endl;

    return 0;
}