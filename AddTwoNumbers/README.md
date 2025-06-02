# Algorithmic-exercises 2
This is a solution for leetcode's **"2. Add Two Numbers"** problemset

https://leetcode.com/problems/add-two-numbers/description/

## Solution1

**Abstract:**

 I Extracted the linked lists into vectors, I reversed these later to be in the order they needed to be for the additions to work. Then I have extracted the member variables into 2 unsigned lonng longs, added those together then added the sum into a linked list. Thus getting the solution.

**Detailed:**
I created a member function to handle the extraction of digits (int listToInt(ListNode *list)). This starts out with a while loop that goes through the list till it hits a nullptr. Within the loop, I push back each node's elements into a new vector.
Once this process is done, I'll take the vector and, using std::reverse(), correct their order.
After this, I simply took the first element of the vector, initialized my sum variable with it, then iterated over the rest of the vector, simply adding elements to the integer by multiplying it by 10 and adding the current element.
This function, called twice, gave me the two numbers that I had to add together.
Here is when my second helper function came into mind, the "ListNode *intToList(int sum)".
This function does the reverse process of the previous one. It extracts the digits into a vector by using the modulus operator. Then reversed the vector again, since by extracting the values from back to front, it reversed the positions. And it is much easier to add elements to the front of a linked list than to the back. It could have been done this way as well, but going through the list every time for every element seemed redundant.

## Solution2

**Abstract:**

 Same as before I extracted the digits into vectors, then i reversed those. after this i implemented a digit addittion logic, that loops through the vectors and adds the current digits together, if the digits sum is greater then 10 I extract the last digit with the modulus operator then add 1 to the carry value which is added to the next digit in the loop. If the loop ends and i still carry a value, that would be pushed back to the end.

