#include <vector>
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwo(ListNode *list1, ListNode *list2)
    {
        ListNode *mergedHead = nullptr;
        ListNode *mergedTail = nullptr;

        while (list1 || list2)
        {
            int value;
            if (!list1)
            {
                value = list2->val;
                list2 = list2->next;
            }
            else if (!list2)
            {
                value = list1->val;
                list1 = list1->next;
            }
            else if (list1->val == list2->val)
            {
                value = list1->val;
                list1 = list1->next;
                list2 = list2->next;
            }
            else if (list1->val < list2->val)
            {
                value = list1->val;
                list1 = list1->next;
            }
            else
            {
                value = list2->val;
                list2 = list2->next;
            }

            ListNode *current = new ListNode(value);
            if (!mergedHead)
            {
                mergedHead = current;
                mergedTail = current;
            }
            else
            {
                mergedTail->next = current;
                mergedTail = mergedTail->next;
            }
        }
        return mergedHead;
    }

    ListNode *mergeKLists(std::vector<ListNode *> &lists)
    {
        // The Plan
        // create local copy
        // create temporary list
        // Merge every 2 list, from local copy untill there is only one left
        // return the head for that

        if (lists.empty())
        {
            return nullptr;
        }

        std::vector<ListNode *> localCopy = lists;
        while (localCopy.size() != 1)
        {
            std::vector<ListNode *> temp;
            ListNode *newListHead = nullptr;
            for (int i = 0; i < localCopy.size(); i += 2)
            {
                if (i + 1 < localCopy.size())
                {
                    temp.push_back(mergeTwo(localCopy[i], localCopy[i + 1]));
                }
                else
                {
                    temp.push_back(localCopy[i]);
                }
            }
            localCopy.clear();
            localCopy.resize(temp.size());
            for (int i = 0; i < temp.size(); i++)
            {
                localCopy[i] = temp[i];
            }
        }
        return localCopy[0];
    }
};