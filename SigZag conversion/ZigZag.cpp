#include <vector>
#include <string>
class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }

        std::vector<std::vector<char>> convertor;
        convertor.resize(s.size());
        for (int i = 0; i < s.size(); i++)
        {
            convertor[i].resize(numRows, ' ');
        }

        int position = 0;
        int depth = 0;
        bool descending = true;

        for (int i = 0; i < s.size(); i++)
        {
            convertor[i][depth] = s[i];
            if (descending)
            {
                depth++;
            }
            else
            {
                depth--;
            }
            if (depth == 0 || depth == numRows - 1)
            {
                descending = !descending;
            }
        }

        std::string solution;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < s.size(); j++)
            {
                if (convertor[j][i] != ' ')
                {
                    solution += convertor[j][i];
                }
            }
        }
        return solution;
    }
};

class Solution2
{
public:
    std::string convert(std::string s, int numRows)
    {
        if (numRows == 1 || numRows >= s.size())
        {
            return s;
        }
        std::vector<std::string> convertor;
        convertor.resize(numRows);
        bool descending = true;
        int row = 0;
        for (char c : s)
        {
            convertor[row] += c;
            if (row == 0 || row == numRows - 1)
            {
                descending = !descending;
            }
            if (descending)
            {
                row++;
            }
            else
            {
                row--;
            }
        }
        std::string solution;
        for (std::string line : convertor)
        {
            solution += line;
        }
        return solution;
    }
};