# Longest Substring without repeating characters

https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without duplicate characters.

**Constraints:**

0 <= s.length <= 5 \* 104
s consists of English letters, digits, symbols and spaces.

## Solutions:

**Solution 1, Brute force Method:**

Simple brute-force approach: I use an "unordered_set" to store characters found so far. I iterate over each character using a nested loop. For each starting index, I move forward using a while loop, stopping either when I reach the end of the string or when a duplicate character is found. During this scan, I keep track of the current substring length. If the current length exceeds the longest seen so far, I update the record. Otherwise, I continue with the next starting index.

**Solution 2, Sliding Window Method:**
Similarly to the first approach, I start with an unordered_set to store characters found so far. Then I initialize two pointers, left and right, both set to 0. I use a while loop that iterates over the entire string. The loop stops when the right pointer reaches the end of the string. On each iteration, I check the current character. If there are no duplicates, I move the right pointer forward. If there is a duplicate, I move the left pointer forward. Since the pointers are integers, calculating the size of the substring is straightforward: I simply subtract the left pointer from the right and add 1 to account for zero-based indexing.