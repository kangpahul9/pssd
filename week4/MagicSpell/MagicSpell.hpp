#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
class MagicSpell {
public:
    string fixTheSpell(string spell){
        int n = spell.size();int j=0;
        string result(n,'0'); string non; 
        for(int i=0; i<n; i++){
            
            
            if(spell[i] == 'A' || spell[i] =='Z' ){
                result[i]=spell[i];
            }
            else {
                result[i]='0';
                non.push_back(spell[i]);
            }
        }
        std::reverse(result.begin(), result.end());j=0;
        for (int i = 0; i < n; i++)
        {
            if (result[i] == '0')
            {
                result[i] = non[j];
                j++;
            }
        }
        return result;
    }
};

