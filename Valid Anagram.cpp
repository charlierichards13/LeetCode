// Given two strings s and t, return true if the two strings are anagrams of each other, otherwise return false.

// An anagram is a string that contains the exact same characters as another string, but the order of the characters can be different.

// Example 1:

// Input: s = "racecar", t = "carrace"

// Output: true
// Example 2:

// Input: s = "jar", t = "jam"

// Output: false
// Constraints:

// s and t consist of lowercase English letters.



class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() == t.length()) {
            
            unordered_map <char, int> CountS;
            unordered_map <char, int> CountT;
            for (int i = 0; i < s.length(); i++) {
                CountS[s[i]]++;
                CountT[t[i]]++;
            }
            // return true if they are anagram
            return CountS == CountT;
        } else {
            return false;
            std::cout << "cannot be anagrams if length differs :)" <<endl;
        }
    }
};
