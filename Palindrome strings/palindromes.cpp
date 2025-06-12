#include <string>
// Given a string s, return the longest palindromic substring in s.
class Solution1
{
public:
    std::string checklLeftRight(const std::string &string, int left, int right)
    {
        while (left >= 0 && right < string.size() && string[left] == string[right])
        {
            left--;
            right++;
        }
        return string.substr(left + 1, right - left - 1);
    }
    std::string longestPalindrome(std::string s)
    {
        std::string longest;
        for (int i = 0; i < s.size(); i++)
        {
            std::string odd = checklLeftRight(s, i, i);
            std::string even = checklLeftRight(s, i, i + 1);
            if (odd.size() > longest.size())
            {
                longest = odd;
            }
            if (even.size() > longest.size())
            {
                longest = even;
            }
        }
        return longest;
    }
};
class Solution2
{
public:
    std::string checkLeftRight(const std::string &string, int left, int right)
    {
        while (left >= 0 && right < string.size() && string[left] == string[right])
        {
            left--;
            right++;
        }
        return string.substr(left + 1, right - left - 1);
    }
    std::string longestPalindrome(std::string s)
    {
        std::string longest;
        for (int i = 0; i < s.size(); i++)
        {
            std::string odd = checkLeftRight(s, i, i);
            std::string even = checkLeftRight(s, i, i + 1);
            if (odd.size() > longest.size())
            {
                longest = odd;
            }
            if (even.size() > longest.size())
            {
                longest = even;
            }
        }
        return longest;
    }
};