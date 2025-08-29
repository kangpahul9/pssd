#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class MagicSpell {
public:
    string fixTheSpell(string spell){
        int n = spell.size();
        string result(n,'0'); string non; 
        for(int i=0; i<n; i++){
            if(spell[i] == 'A' || spell[i] =='Z' ){
                result.push_back(spell[i]);
            }
        }
        std::reverse(result.begin(), result.end());int j=0;
        for (int i = 0; i < n; i++)
        {
            if(spell[i] == 'A' || spell[i] =='Z' ){
                spell[i] = result[j++];
            }
        }
        return spell;
    }
};

