"""
Arturo Olivares
March 22, 2023

LeetCode - 13. Roman to Integer

Constraints:

    1 <= s.length <= 15
    s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
    It is guaranteed that s is a valid roman numeral in the range [1, 3999].

"""

def roman_to_int(s: str) -> int:
    ans = 0
    equivalencies = {
        'I': 1,
        'V': 5,
        'X': 10,
        'L': 50,
        'C': 100,
        'D': 500,
        'M': 1000
    }

    i = 0
    while i < len(s):
        if i+1 < len(s) and equivalencies[s[i+1]] > equivalencies[s[i]]:
            ans += (equivalencies[s[i+1]] - equivalencies[s[i]])
            i += 2
        else:
            ans += equivalencies[s[i]]
            i += 1

    return ans


if __name__ == "__main__":
    s = input("Roman: ")
    print("Int:", roman_to_int(s))
