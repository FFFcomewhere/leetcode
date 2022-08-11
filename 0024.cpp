#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *cur = head->next;
        head->next = swapPairs(cur->next);
        cur->next = head;
        return cur;
    }
};

/*
分析:

方法:

总结:

*/