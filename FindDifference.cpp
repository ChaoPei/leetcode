// Given two strings s and t which consist of only lowercase letters.

// String t is generated by random shuffling string s and then add one more letter at a random position.

// Find the letter that was added in t.

// Example:

// Input:
// s = "abcd"
// t = "abcde"

// Output:
// e

// Explanation:
// 'e' is the letter that was added.



class Solution {
public:
    char findTheDifference(string s, string t) {
        int array[26] = {0};
        string::size_type idx = 0;
        while(idx != s.size()) {
            ++array[s[idx++] - 'a'];
        }
        
        idx = 0;
        while(idx != t.size()) {
            --array[t[idx++] - 'a'];
        }
        
        for(int i = 0; i < 26; ++i) {
            if(array[i] != 0)
                return 'a' + i;
        }
        
        return ' ';
    }
};