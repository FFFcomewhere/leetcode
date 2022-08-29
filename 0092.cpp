#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        //设置哑节点
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        int i = 1;
        //反转区间左侧前一个节点
        ListNode *midLeft = dummyNode;
        for (; i < left; i++)
        {
            midLeft = midLeft->next;
        }

        //反转区间右侧后一个节点
        ListNode *tempNode = midLeft;
        for (; i <= right; i++)
        {
            tempNode = tempNode->next;
        }
        ListNode *midRight = tempNode->next;
        tempNode->next = nullptr;

        //切割出子链表，用于反转
        ListNode *subTail = midLeft->next;

        //反转子联表
        ListNode *subHead = reverse(subTail);

        //拼接
        midLeft->next = subHead;
        subTail->next = midRight;

        return dummyNode->next;
    }

    ListNode *reverse(ListNode *cur)
    {
        ListNode *pre = nullptr;

        for (; cur != nullptr;)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

/*
分析:  模拟 切割

方法:

总结:

*/