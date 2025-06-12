# Zigzag Conversion

https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

**Constraints:**

1 <= s.length <= 1000
s consists of English letters (lower-case and upper-case), ',' and '.'.
1 <= numRows <= 1000

# Solutions:

**Solution 1:**
I really wanted to do a proper zig-zag pattern, so I made a 2d vector for it. I initialized the outer vector to be the size of the string, then initialized the inner vectors to be the size of the depth. Also, I filled the vectors with blank spaces (' ') for visualization and logic purposes. 
After this setup, I looped through the input string and placed characters into the matrix based on the current direction..
At the end with the help of a nested for loop, I simply extracted the characters row by row. Ignoring the blank spaces this gave me the "encoded message".

**Solution 2:**
This is a more straight forward and more optimal solution. Since the exercise is only interested in the encoded message, there is no need for an actual zig zag patterned matrix. I could just simply set up a vector of strings, to which I add the characters in a descending and ascending order.
I simply set up a range based for loop, which took each character from the string, and added it to the substrings based on the descending Boolean flag being true or false.
At the end, I just added together the strings, thus making the cypher work.

