#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int start = 0;
        int end = 0;

        for (int i = 0; i < s.length(); i++) {
            // Expand around a single character center (odd length palindromes like "aba")
            int len1 = expandAroundCenter(s, i, i);
            
            // Expand around the gap between two characters (even length palindromes like "abba")
            int len2 = expandAroundCenter(s, i, i + 1);
            
            // Get the maximum length found from both types of centers
            int len = max(len1, len2);
            
            // If we found a longer palindrome, update the start and end boundaries
            if (len > end - start) {
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }

        // Return the longest palindromic substring
        return s.substr(start, end - start + 1);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // The length of the palindrome is (right - 1) - (left + 1) + 1 = right - left - 1
        return right - left - 1;
    }
};