#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


//hash 表  针对这种重复元素问题，直接上hash
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_set<ListNode *> h;
        ListNode *copyA = headA, *copyB = headB;

        for (; copyA != nullptr || copyB != nullptr;)
        {
            if (copyA != nullptr)
            {
                if (h.count(copyA) != 0)
                {
                    return copyA;
                }
                h.insert(copyA);
                copyA = copyA->next;
            }

            if (copyB != nullptr)
            {
                if (h.count(copyB) != 0)
                {
                    return copyB;
                }
                h.insert(copyB);
                copyB = copyB->next;
            }
        }
        return nullptr;
    }
};

//双指针
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        ListNode *ha = headA, *hb = headB;

        for (; ha != hb;)
        {
            if (ha == nullptr)
            {
                ha = headB;
            }
            else
            {
                ha = ha->next;
            }

            if (hb == nullptr)
            {
                hb = headA;
            }
            else
            {
                hb = hb->next;
            }
        }
        return ha;
    }
};

/*
分析: 使用双指针，如果一次遍历两个链表，最后的距离会是一样的，假设链表长度分别为a,b;相交部分为c；a+b-c = b+a-c
        必定会交于同一个点。

方法: 双指针

总结: 本质还是一个重复元素和步长的问题，可以使用双指针来解决。


*/