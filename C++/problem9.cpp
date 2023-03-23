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

//Arithmetic approach - better solution, no use of any data strcture.
bool isPalindrome2(int num){

    if(num < 0 || (num % 10 == 0 && num != 0)){
    /*
        Restrictions to num:
            - Negative numbers can't be palindrome numbers
            - Numbers ending with 0 can't be palindrome numbers,
              except zero itself.
    
    */
        return false;
    }

    int reversed = 0; // Initialize a variable to store the reversed right half of the number

    while(num > reversed){ //This condition is what determines from which digit is the half
        reversed = reversed * 10 + num % 10; // Reverse the digits of the right half of the number and store them in 'reversed'
        num /= 10; // Remove the last digit from the left half of the number
    }


    // Compare the left half of the number to the reversed right half to determine if it's a palindrome
    return num == reversed || num == reversed / 10;


}

int main(){

    std::vector<int>fake_str, reversed_str;
    int number;
    std::cin >> number;

    std::cout << std::boolalpha << isPalindrome(number);

    return 0;
}

