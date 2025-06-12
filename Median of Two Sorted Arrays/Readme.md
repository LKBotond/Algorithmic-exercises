# Median of Two Sorted Arrays:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).

**Constraints:**

nums1.length == m
nums2.length == n
0 <= m <= 1000
0 <= n <= 1000
1 <= m + n <= 2000
-106 <= nums1[i], nums2[i] <= 106

# Solutions:
**Approach 1:**
The first and slowest option is to sort the vectors into a larger vector, then get to the “median” that way. It is easy enough, once the sorting is done, I can just test the combined size if it is even or odd, then return either the median or the result of the average of the 2 positions.

**Approach 2:**
Since the “median “is the thing that I'm interested in, there is no need to sort both arrays till the end. Since the sizes are known, I Know where the midpoint should be, this way I can, sort the arrays together till I get the midpoint, then either return that, or the average between the midpoint and the one element before it. Since arrays are 0 indexed and all.

**Approach 3:**
TO BE IMPLEMENTED, most likely solution would be a binary search algorythm.
