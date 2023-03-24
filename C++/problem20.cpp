/*

Arturo Olivares 
March 23, 2023

LeetCode - 20. Valid Parentheses (One of my favorite problems!)

Constraints:

    1 <= s.length <= 10^4
    s consists of parentheses only '()[]{}'.

*/

#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char>scanner;


        if(s[0] == ')' || s[0] == ']' || s[0] == '}' ){
            return false;
        }

        for(int i{0}; i<s.size(); i++){
            switch(s[i]){
                case '(':
                    scanner.push(s[i]);
                    break;
                case '[':
                    scanner.push(s[i]);
                    break;
                case '{':
                    scanner.push(s[i]);
                    break;
                case ')':
                    if(scanner.top() != '('){
                        return false;
                    }
                    scanner.pop();
                    break;
                case ']':
                    if(scanner.top() != '['){
                        return false;
                    }
                    scanner.pop();
                    break;
                case '}':
                    if(scanner.top() != '{'){
                        return false;
                    }
                    scanner.pop();
                    break;
            }
        }
        return true;
    }
};

int main(){
    std::string str;
    std::cin >> str;
    Solution ans;

    std:: cout << std::boolalpha << ans.isValid(str);
}