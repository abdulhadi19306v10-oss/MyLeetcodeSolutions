#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charIndexMap;
        int left = 0;
        int maxLength = 0;
        
        for (int right = 0; right < s.length(); right++) {
            char currentChar = s[right];
            
            // If the character is in the map AND its last seen index is inside our current window
            if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
                // Jump the left pointer to the right of the previous occurrence
                left = charIndexMap[currentChar] + 1;
            }
            
            // Update the map with the current character's new index
            charIndexMap[currentChar] = right;
            
            // Calculate the window size and update the maximum length found so far
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};