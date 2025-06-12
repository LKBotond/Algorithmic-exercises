#include <vector>
class Solution1
{
public:
    bool isPalindrome(int x)
    {
        std::vector<int> extracted;
        while (x > 0)
        {
            int digit = x % 10;
            x = x / 10;
            extracted.push_back(digit);
        }

        int left;
        int right;
        bool palindrome = false;
        if (extracted.size() % 2 == 0)
        {
            right = extracted.size() / 2;
            left = right - 1;
            while (extracted[left] == extracted[right])
            {
                left--;
                right++;
                if (left == 0)
                {
                    palindrome = true;
                }
            }
        }
        else
        {
            left = extracted.size() / 2 - 1;
            right = extracted.size() / 2 + 1;
            while (extracted[left] == extracted[right])
            {
                left--;
                right++;
                if (left == 0)
                {
                    palindrome = true;
                }
            }
        }
        return palindrome;
    }
};
class Solution2
{
public:
    bool isPalindrome(int x)
    {
        std::vector<int> extracted;
        while (x > 0)
        {
            int digit = x % 10;
            x = x / 10;
            extracted.push_back(digit);
        }

        int left;
        int right;
        if (extracted.size() % 2 == 0)
        {
            right = extracted.size() / 2;
            left = right - 1;
        }
        else
        {
            left = extracted.size() / 2 - 1;
            right = extracted.size() / 2 + 1;
        }
        while (left >= 0 && right < extracted.size())
        {
            if (extracted[left] != extracted[right])
            {
                return false;
            }
            left--;
            right++;
        }
        return true;
    }
};

class Solution3
{
public:
    bool isPalindrome(int x)
    {
        int original = x;

        int reversed = 0;

        while (x > 0)
        {
            int digit = x % 10;
            x = x / 10;
            reversed = reversed * 10 + digit;
        }
        if (original == reversed)
        {
            return true;
        }

        return false;
    }
};