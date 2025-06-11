#include <unordered_set>
#include <string>

// brute forcey method
class Solution1
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> charset;
        int longest = 0;
        int length = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int iterator = i;
            while (iterator < s.size() && charset.find(s[iterator]) == charset.end())
            {
                length++;
                iterator++;
                charset.insert(s[iterator]);
            }
            if (length > longest)
            {
                longest = length;
            }
            length = 0;
            charset.clear();
        }
        return longest;
    }
};

// Revritten with sliding window technique
class Solution2
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        std::unordered_set<char> charset;
        int left = 0;
        int right = 0;
        int longest = 0;

        while (right < s.size())
        {
            if (charset.find(s[right]) == charset.end())
            {//qwertyuiopr
                charset.insert(s[right]);
                longest = std::max(longest, right - left + 1);
                right++;
            }
            else
            {
                charset.erase(s[left]);
                left++;
            }
        }

        return longest;
    }
};