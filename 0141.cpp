#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//hash  时间O(n) 空间O(n)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, bool> h;

        for (; head != nullptr;)
        {
            if (h.count(head) != 0)
            {
                return true;
            }
            else
            {
                h[head] = true;
                head = head->next;
            }
        }
        return false;
    }
};

//标记重复元素 但是只针对取值有范围的时候 时间O(n) 空间O(1)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        int flag_num = 100000;

        for (; head != nullptr;)
        {
            if (head->val == flag_num)
            {
                return true;
            }
            else
            {
                head->val = flag_num;
                head = head->next;
            }
        }
        return false;
    }
};

//快慢指针
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return false;
        }
        ListNode *slow = head, *fast = head->next;

        for (; slow != fast;)
        {
            if (fast == nullptr || fast->next == nullptr)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }
        return true;
    }
};


/*
分析:

方法:

总结:

*/