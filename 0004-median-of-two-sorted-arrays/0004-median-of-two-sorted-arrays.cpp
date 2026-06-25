#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    // We always want to run binary search on the smaller array for efficiency.
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0, high = x;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        // If partition is 0, there is nothing on the left side. Use -infinity.
        double maxLeftX = (partitionX == 0) ? -1e9 : nums1[partitionX - 1];
        double minRightX = (partitionX == x) ? 1e9 : nums1[partitionX];

        double maxLeftY = (partitionY == 0) ? -1e9 : nums2[partitionY - 1];
        double minRightY = (partitionY == y) ? 1e9 : nums2[partitionY];

        // Check if we found the perfect split
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((x + y) % 2 == 0) {
                return (max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2.0;
            } else {
                return max(maxLeftX, maxLeftY);
            }
        } 
        // We are too far on the right side of nums1. Move left.
        else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } 
        // We are too far on the left side of nums1. Move right.
        else {
            low = partitionX + 1;
        }
    }
    return 0.0; // Fallback
    }
};