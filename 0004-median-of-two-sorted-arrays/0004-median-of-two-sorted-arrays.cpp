#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // 1. Merge the two arrays into one
    vector<double> merged;
    merged.reserve(nums1.size() + nums2.size()); // Pre-allocate memory for efficiency
    merged.insert(merged.end(), nums1.begin(), nums1.end());
    merged.insert(merged.end(), nums2.begin(), nums2.end());

    // 2. Sort the merged array in ascending order
    sort(merged.begin(), merged.end());

    // 3. Count the number of values
    int n = merged.size();

    // Edge case: if both arrays are empty
    if (n == 0) {
        return 0.0; 
    }

    // 4. Use an if-else statement to find and return the median
    if (n % 2 == 0) {
        // If the count is even, the median is the average of the two middle elements
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    } else {
        // If the count is odd, the median is the exact middle element
        return merged[n / 2];
    }
}
};