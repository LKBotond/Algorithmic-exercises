#include <vector>

/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution1
{
public:
    unsigned long long listToInt(ListNode *list)
    {
        ListNode *current = list;
        std::vector<int> reversed;
        while (current != nullptr)
        {
            reversed.push_back(current->val);
            current = current->next;
        }
        std::reverse(reversed.begin(), reversed.end());

        unsigned long long solution = reversed[0];
        for (int digit = 1; digit < reversed.size(); digit++)
        {
            solution = solution * 10 + reversed[digit];
        }
        return solution;
    }

    ListNode *intToLIst(unsigned long long sum)
    {
        std::vector<int> unreversed;
        while (sum > 0)
        {
            unreversed.push_back(sum % 10);
            sum /= 10;
        }
        std::reverse(unreversed.begin(), unreversed.end());
        ListNode *nodeHead = new ListNode(unreversed[0]);
        for (int i = 1; i < unreversed.size(); i++)
        {
            ListNode *newNode = new ListNode(unreversed[i]);
            newNode->next = nodeHead;
            nodeHead = newNode;
        }
        return nodeHead;
    }
    ListNode *
    addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int int1 = listToInt(l1);
        int int2 = listToInt(l2);

        int sum = int1 + int2;
        return intToLIst(sum);
    }
};

class Solution2
{
public:
    std::vector<int> linkedListToVector(ListNode *list)
    {
        std::vector<int> extracted;
        while (list)
        {
            extracted.push_back(list->val);
            list = list->next;
        }
        return extracted;
    }
    ListNode *vectorToLinkedList(std::vector<int> sum)
    {
        ListNode *head = new ListNode(sum[0]);
        ListNode *tail = head;
        for (int i = 1; i < sum.size(); i++)
        {
            tail->next = new ListNode(sum[i]);
            tail = tail->next;
        }
        return head;
    }
    ListNode *
    addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        // extracting vectors
        std::vector<int> v1 = linkedListToVector(l1);
        std::vector<int> v2 = linkedListToVector(l2);

        // flipping vectors
        std::reverse(v1.begin(), v1.end());
        std::reverse(v2.begin(), v2.end());

        // reinventing math
        int length = std::max(v1.size(), v2.size());
        std::vector<int> sum;
        int carry = 0;
        for (int i = 0; i < length; i++)
        {
            int current_Sum = 0 + carry;
            carry = 0;
            if (i < v1.size())
            {
                current_Sum += v1[i];
            }
            if (i < v2.size())
            {
                current_Sum += v2[i];
            }
            if (current_Sum >= 10)
            {
                carry += 1;
                current_Sum = current_Sum % 10;
            }
            sum.push_back(current_Sum);
        }
        if (carry > 0)
        {
            sum.push_back(carry);
        }

        return vectorToLinkedList(sum);
    }
};