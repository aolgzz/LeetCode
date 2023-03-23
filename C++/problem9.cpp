/*

Arturo Olivares
March 22, 2023

LeetCode - 9. Palindrome Number

*/

#include <iostream>
#include <vector>
#include <algorithm>

//First attempt: No strings, but use of DS. Time: O(n)
bool isPalindrome(int num){
    if(num < 0){
        return false;
    }

    std::vector<int>fake_str, reversed_str;
    while(num > 0){
        fake_str.push_back(num % 10);
        num/=10;
    }

    reversed_str = fake_str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    return reversed_str == fake_str;

}

int main(){

    std::vector<int>fake_str, reversed_str;
    int number;
    std::cin >> number;

    std::cout << std::boolalpha << isPalindrome(number);

    return 0;
}

