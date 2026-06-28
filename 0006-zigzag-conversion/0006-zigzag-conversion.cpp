#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // Edge case: if 1 row or the string is shorter than the number of rows,
        // no zigzag is possible. Return the original string.
        if (numRows <= 1 || numRows >= s.length()) {
            return s;
        }

        // Create an array of strings to represent each row
        vector<string> rows(numRows);
        int currentRow = 0;
        bool goingDown = false;

        // Traverse the string and place characters in the correct row
        for (char c : s) {
            rows[currentRow] += c;

            // Change direction if we hit the top (0) or the bottom (numRows - 1)
            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            // Move the row pointer up or down
            currentRow += goingDown ? 1 : -1;
        }

        // Concatenate all the rows together
        string result = "";
        for (const string& row : rows) {
            result += row;
        }

        return result;
    }
};