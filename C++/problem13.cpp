/*

Arturo Olivares
March 22, 2023

LeetCode - 13. Roman to Integer

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/

#include <unordered_map>
#include <iostream>
#include <string>

int romanToInt(std::string str){
    int ans = 0;
    std::unordered_map<char, int>equivalencies {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 100}
    };

    for(int i{0}; i<str.length(); i++){
        if(equivalencies[str[i+1]]>equivalencies[str[i]]){
            ans+= (equivalencies[str[i+1]] - equivalencies[str[i]]);
            i++;
        }else{
            ans+= equivalencies[str[i]];
        }
    }

    return ans;

}


int main(){

    std::string str;
    std::cout << "Roman: ";
    std::cin >> str;
    std::cout <<"Int: "<< romanToInt(str);

    return 0;
}