#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//hash
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> h;
        for(;head!=NULL;){
            if(h.count(head)){
                return head;
            } 
            h.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

//快慢指针
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *fast = head, *slow = head;

        for (; fast != nullptr;)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                return nullptr;
            }
            fast = fast->next->next;

            if (fast == slow)
            {
                ListNode *ptr = head;
                for (; ptr != slow;)
                {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};

/*
分析:   使用unordered_set来记录节点，如果节点已经存在，则说明有环，返回该节点。
        使用快慢指针，快指针每次走两步，慢指针每次走一步，如果有环，则快指针会追上慢指针，否则快指针会走到末尾。
        如果没有环，则快指针会走到末尾，慢指针会走到末尾，返回nullptr。

方法:   哈希表 快慢指针

总结:   

*/