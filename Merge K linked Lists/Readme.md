# Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

https://leetcode.com/problems/merge-k-sorted-lists/description/

**Constraints:**

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 10^4.

# Solution

This problem was a bit tricky, until I realized that,**I don’t need to sort and merge the entire vector of lists all at once.**

From that point on, it was just the [Merge Two Sorted Lists](../Merging%20linked%20lists/Readme.md) problem all over again, with the added caveat that **duplicates may now exist**.

So, I reused my solution from the earlier problem and updated the logic to copy only one of each duplicate value when merging. That gave me a function that correctly merges two sorted lists **without repeating values**.

At this point, the exercise devolved into **repeatedly merging pairs of lists** in the vector until only one list remained.

**I solved this by:**

1. Creating a local copy of the input vector.
2. Using a `while` loop that runs until only one list remains.
3. In each iteration, I used a `for` loop to merge every two adjacent lists in the current vector, storing the results in a temporary vector.
4. Once all pairs were processed, I replaced the local copy with the temporary vector.

Eventually, the local copy is reduced to a vector with the size of 1, of which returning the "[0]"th element gave me the merged lists.
