#include <vector>
#include <algorithm>

/*
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).


*/
class Approach1
// merge the arrays
// get the midpoint
// return the median
{
public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // merging the arrays
        int i = 0;
        int j = 0;
        std::vector<int> result;
        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] < nums2[j])
            {
                result.push_back(nums1[i]);
                i++;
            }
            else
            {
                result.push_back(nums2[j]);
                j++;
            }
        }
        while (i < nums1.size())
        {
            result.push_back(nums1[i]);
            i++;
        }
        while (j < nums2.size())
        {
            result.push_back(nums2[j]);
            j++;
        }

        // getting the mid point
        int combined_Size = nums1.size() + nums2.size();
        int mid_Point = combined_Size / 2;

        // returning the median
        if (combined_Size % 2 == 0)
        {
            return (result[mid_Point - 1] + result[mid_Point]) / 2.0;
        }
        else
        {
            return result[mid_Point];
        }
    }
};
class Approach2
{
    // since I'm only interested in the median I do not have to sort the whole array, only keep track of the current element and the one before it (in case of even total size), thusb there is no need to copy the content of the vectors;

public:
    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        // find mid point
        int mid_Point = (nums1.size() + nums2.size()) / 2;

        // Merge only until we reach the middle
        int nums1_Iterator = 0;
        int nums2_Iterator = 0;
        int common_Iterator = 0;

        int current = 0;
        int previous = 0;
        while (common_Iterator <= mid_Point)
        {
            previous = current;
            if (nums1_Iterator < nums1.size() && (nums2_Iterator >= nums2.size() || nums1[nums1_Iterator] < nums2[nums2_Iterator]))
            {
                current = nums1[nums1_Iterator++];
            }
            else
            {
                current = nums2[nums2_Iterator++];
            }

            common_Iterator++;
        }

        // returning the median
        if (mid_Point % 2 == 0)
        {
            return (previous + current) / 2.0;
        }
        else
        {
            return current;
        }
    }
};