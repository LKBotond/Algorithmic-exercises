# Reverse Integer

https://leetcode.com/problems/reverse-integer/
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

**Constraints:**

-2^31 <= x <= 2^31 - 1

**Solution:**
I started by declaring an integer called reversed and initializing it to 0. Then, I iterated through the input number by repeatedly extracting the last digit using the modulus operator (%). I built the reversed number by multiplying the current reversed value by 10 and adding the extracted digit.

For boundary checking, I used constants from <climits> (like INT_MAX and INT_MIN) to ensure that the reversed value would not overflow a 32-bit signed integer. This helped me safely return 0 if the result would go out of bounds.
