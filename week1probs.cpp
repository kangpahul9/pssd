#include <iostream>
#include <vector>
#include <string>
using namespace std;

class SquareOfDigits
{
public:
    int getMax(vector <string> data){
        int area=1, maxArea=1,n=data.size();
        string str1="",str2="";
        for (int row1 = 0; row1 < n; row1++)
        {
            str1=data[row1];
            for (int row2 = row1+1; row2 < n; row2++)
            {
                str2=data[row2]; 
            for (int col1 = 0; col1 < str2.size(); col1++)
            {
             for (int col2 = col1+1; col2 < str2.size(); col2++)
             {
                if (str1[col1]==str1[col2] && str2[col1] == str2[col2] && str1[col1]==str2[col1])
                {
                    area=((row2-row1)+1)*((col2-col1)+1);
                }
             }
             maxArea=max(maxArea,area);
            }
            }
        }
        return maxArea;
        
    }
};

int main() {
    SquareOfDigits s;

    vector<vector<string>> testCases = {
        {"12"},
        {"1255", "3455"},
        {"42101", "22100", "22101"},
        {"1234567890"},
        {"9785409507",
         "2055103694",
         "0861396761",
         "3073207669",
         "1233049493",
         "2300248968",
         "9769239548",
         "7984130001",
         "1670020095",
         "8894239889",
         "4053971072"}
    };

    vector<int> expected = {1, 4, 9, 1, 49};

    for (size_t i = 0; i < testCases.size(); i++) {
        int result = s.getMax(testCases[i]);
        cout << "Test case " << i << ": " << result 
             << " (Expected " << expected[i] << ")" << endl;
    }

    return 0;
}

