#include <limits.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Always binary search on the smaller array
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }

    int m = nums1Size, n = nums2Size;
    int lo = 0, hi = m;
    int halfLen = (m + n + 1) / 2;

    while (lo <= hi) {
        int i = (lo + hi) / 2;       // partition in nums1
        int j = halfLen - i;         // partition in nums2

        int nums1LeftMax  = (i == 0) ? INT_MIN : nums1[i - 1];
        int nums1RightMin = (i == m) ? INT_MAX : nums1[i];
        int nums2LeftMax  = (j == 0) ? INT_MIN : nums2[j - 1];
        int nums2RightMin = (j == n) ? INT_MAX : nums2[j];

        if (nums1LeftMax <= nums2RightMin && nums2LeftMax <= nums1RightMin) {
            // Perfect partition found
            if ((m + n) % 2 == 1) {
                return (double)(nums1LeftMax > nums2LeftMax ? nums1LeftMax : nums2LeftMax);
            } else {
                int maxLeft  = nums1LeftMax  > nums2LeftMax  ? nums1LeftMax  : nums2LeftMax;
                int minRight = nums1RightMin < nums2RightMin ? nums1RightMin : nums2RightMin;
                return (maxLeft + minRight) / 2.0;
            }
        } else if (nums1LeftMax > nums2RightMin) {
            hi = i - 1;   // i is too large, move left
        } else {
            lo = i + 1;   // i is too small, move right
        }
    }

    return 0.0;
}