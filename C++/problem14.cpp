/*

Arturo Olivares
March 22, 2023

LeetCode - 14. Longest Common Prefix

*/

#include <string>
#include <vector>
#include <iostream>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {

        std::string LCP = "";

        //Find shortest string in the whole vector
        int min_size = strs[0].size();
        for(int i{0}; i<strs.size(); i++){
            if(min_size > strs[i+1].size()){
                min_size = strs[i+1].size();
            }
        }

        for(int i{0}; i<min_size; i++){
            char curr = strs[0][i]; // Get the i-th character of the first string in the vector
            for(int j{0}; j<strs.size(); j++){
                if(strs[j][i]!=curr){ // If the i-th character of any string is different from the i-th character of the first string,
                    return LCP;      // we have found the end of the longest common prefix.
                }
            }
            LCP += curr; // If all strings have the same i-th character, add it to the longest common prefix
        }

        return LCP;

    }
};

int main(){

    //Example
    std::vector<std::string>array = {"flower", "flow","flight"};

    Solution ans;
    std::cout << ans.longestCommonPrefix(array);

    return 0;
}