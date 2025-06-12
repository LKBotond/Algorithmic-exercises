# Palindrome Number

https://leetcode.com/problems/palindrome-number/description/

Given an integer x, return true if x is a palindrome, and false otherwise.

Follow up: Could you solve it without converting the integer to a string?

# Solutions:

**Solution 1 and 2** follow a vector-based approach, I simply extracted the digits into a vector, then with the help of a while loop I went through said vector from the middle.

The difference between the 2 is the way I check the boundaries. In solution 1 I rely on implicit checks and loop breaks, whilst in solution 2 I did proper explicit checking.

**Solution 3:**
Solution 3 simply reverses the integer and compares it to the original, if the two match I simply return true.
