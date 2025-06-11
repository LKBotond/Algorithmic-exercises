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
            if (descending)
            {
                for (int j = 0; j <= numRows; j++)
                {
                    convertor[i][j] = s[position];
                    position++;
                    depth++;
                    if (position == s.size())
                    {
                        break;
                    }
                }
                if (depth == numRows)
                {
                    descending = false;
                }
            }
            else
            {
                depth = depth - 1;
                convertor[i][depth] == s[position];
                position++;
                if (position == s.size())
                {
                    break;
                }
                if (depth == 0)
                {
                    descending = true;
                }
            }
        }
        std::string solution;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < numRows + 1; j++)
            {
                if (convertor[i][j] != ' ')
                {
                    solution.push_back(convertor[i][j]);
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
                descending = !!!descending;
            }
            if (descending)
            {
                row = row - 1;
            }
            else
            {
                row = row + 1;
            }
        }
        std::string solution;
        for (std::string line : convertor)
        {
            solution+=line;
        }
        return solution;
    }
};