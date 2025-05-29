#include <vector>
#include <unordered_map>
#include <algorithm>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
*/

class Solution
{
public:
    // this one bruteforces through every possible position in the array
    std::vector<int> bruteForcedTwoSum(std::vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                    return {i, j};
            }
        }
        return {};
    }
    // this one is s slightly less brute forcey way to get the indices, first it creates an array of indices
    // then it sorts them by their coresponding numeric values ascending order
    // then it starts looking for the answer, by moving right or left the indices based on if the target is greater or smaller then the current sum
    std::vector<int> slightlyLessBruteForcedTwoSums(std::vector<int> &nums, int target)
    {
        std::vector<int> indices(nums.size());
        for (int i = 0; i < nums.size(); i++)
        {
            indices[i] = i;
        }

        std::sort(indices.begin(), indices.end(), [&](int a, int b)
                  { return nums[a] < nums[b]; });
        int left = 0;
        int right = nums.size() - 1;
        while (true)
        {
            int sum = nums[indices[left]] + nums[indices[right]];
            if (sum == target)
            {
                return {indices[left], indices[right]};
            }
            else if (sum < target)
            {
                left++;
            }
            else
            {
                right--;
            }
            if (left == right)
            {
                return {};
            }
        }
    }

    // this one works by storing the value of the index already visited in the hashTable
    // on every iteration it looks back at the hash table if the value is already stored, if yes, then returns it if not, full steam ahead till we find it
    std::vector<int> optimized(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++)
        {
            int missing_Value = target - nums[i];
            if (table.count(missing_Value))
            {
                return {table[missing_Value], i};
            }
            table[nums[i]] = i;
        }
        return {};
    }
};