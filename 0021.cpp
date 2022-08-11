#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//额外开数组   O(N) O(1)
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *list = new ListNode(-1);
        ListNode *list_copy = list;

        for (; list1 && list2;)
        {
            if (list1->val < list2->val)
            {
                list->next = list1;
                list1 = list1->next;
            }
            else
            {
                list->next = list2;
                list2 = list2->next;
            }
            list = list->next;
        }

        if (list1 != nullptr)
        {
            list->next = list1;
        }
        else
        {
            list->next = list2;
        }

        return list_copy->next;
    }
};
//递归写法
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
        {
            return list2;
        }
        else if (list2 == nullptr)
        {
            return list1;
        }
        else if (list2->val < list1->val)
        {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
        else
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
    }
};

/*
分析:

方法:

总结:

*/