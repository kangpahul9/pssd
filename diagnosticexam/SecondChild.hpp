#include <iostream>
#include <string>
using namespace std;

class SecondChild {
public:
    string chooseName(string father, string mother, string child1, string gender) {
        string fatherFirst = father.substr(0, father.find(" "));
        string fatherSecond = father.substr(father.find(" ") + 1);

        string motherFirst = mother.substr(0, mother.find(" "));
        string motherSecond = mother.substr(mother.find(" ") + 1);

        string childFirst = child1.substr(0, child1.find(" "));
        string childSecond = child1.substr(child1.find(" ") + 1);

        string child1Gender = (isVowel(childFirst[0]) ? "Girl" : "Boy");

        if (child1Gender != gender) {
            if (gender == "Boy") {
                return fatherSecond + " " + fatherFirst;
            } else {
                return motherSecond + " " + motherFirst;
            }
        }

        // Rule 2: Same genders
        if (gender == "Boy") {
            return fatherFirst + " " + childSecond; 
        }else {
            return motherFirst + " " + childSecond;
        }
        return "";
    }

private:
    bool isVowel(char c) {
        c = toupper(c);
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y');
    }
};


