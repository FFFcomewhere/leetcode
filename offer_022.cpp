#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//hash 时间On 空间On
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> h;
        ListNode *headCopy = head;
        for (; headCopy != nullptr;)
        {
            if (h.count(headCopy))
            {
                return headCopy;
            }

            h.insert(headCopy);
            headCopy = headCopy->next;
        }

        return nullptr;
    }
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;

        for(;fast!=nullptr;){
            slow = slow->next;
            
            if(fast->next == nullptr){
                return nullptr;
            }
            fast = fast->next->next;

            if(slow == fast){
                ListNode* ptr = head;
                for(;slow != ptr;){
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }

        }

        
        return nullptr;
    }
};

//快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        for (; fast != nullptr;)
        {
            slow = slow->next;

            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;

            if (slow == fast)
            {
                ListNode *ptr = head;
                for (; slow != ptr;)
                {
                    slow = slow->next;
                    ptr = ptr->next;
                }
                return ptr;
            }
        }

        return nullptr;
    }
};

/*
分析: 方法一：hash表存储，直接找到重复元素
      方法二： 快慢指针 参考0142

方法:

总结:

*/