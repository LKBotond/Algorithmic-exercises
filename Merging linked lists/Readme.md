# Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

https://leetcode.com/problems/merge-two-sorted-lists/description/

**Constraints:**

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both list1 and list2 are sorted in non-decreasing order.

# Solution:
This was a straightforward linked list exercise. The core challenges were:

- The two input lists might be of different sizes.

- I didn’t know in advance which list would be longer.

- I needed to maintain a reference to the head of the new merged list.

I solved this, by using a while loop that continues as long as at least one of the input lists is not fully traversed. Inside the loop, I first check if one of the lists is exhausted. In that case, I take the value from the other list. If both lists have elements remaining, I compare their current values and copy the smaller one.

Because the original lists might be used elsewhere in a theoretical application, I chose to copy values rather than reuse existing nodes. This avoids side effects that could lead to difficult bugs.

Each selected value is used to create a new ListNode, which is then added to the merged list. For the merging logic:
- If the merged list is empty (i.e., the head is null), I set the new node as the head.

- If the head exists but there is no next node yet, I assign the new node to be the tail, and connect head->next to it.

- For all subsequent nodes, I append the new node to tail->next and update the tail pointer.

This approach results in a new merged list with elements in ascending order, preserving the sorted nature of the input lists.