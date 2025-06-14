
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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
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
            }
            else if (!mergedHead->next)
            {
                mergedTail = current;
                mergedHead->next = mergedTail;
            }
            else
            {
                mergedTail->next = current;
                mergedTail = mergedTail->next;
            }
        }
        return mergedHead;
    }
};
