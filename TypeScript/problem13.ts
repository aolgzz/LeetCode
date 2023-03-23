/*

Arturo Olivares
March 22, 2023

LeetCode - 13. Roman to Integer

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

*/

function romanToInt(s: string): number {
    let ans = 0;
    const equivalencies: { [key: string]: number } = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    };

    let i = 0;
    while (i < s.length) {
        if (i+1 < s.length && equivalencies[s[i+1]] > equivalencies[s[i]]) {
            ans += (equivalencies[s[i+1]] - equivalencies[s[i]]);
            i += 2;
        } else {
            ans += equivalencies[s[i]];
            i += 1;
        }
    }

    return ans;
}

//Put your example
console.log("Int:", romanToInt("MCMLXXXIV"));

