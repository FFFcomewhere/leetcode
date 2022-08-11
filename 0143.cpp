#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//vector 进行存储
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }

        vector<int> nums;
        ListNode *headCopy = head;
        for (; headCopy;)
        {
            nums.push_back(headCopy->val);
            headCopy = headCopy->next;
        }

        int n = nums.size();
        ListNode *res = new ListNode;
        ListNode *resCopy = res;
        for (int i = 0; i < n / 2; i++)
        {
            ListNode *temp1 = new ListNode;
            temp1->val = nums[i];
            res->next = temp1;
            res = res->next;
            //对于奇数，防止重复取中间的元素
            if (n % 2 != 0 && i == n / 2 - 1)
            {
                continue;
            }

            ListNode *temp2 = new ListNode;
            temp2->val = nums[n - 1 - i];
            res->next = temp2;
            res = res->next;
        }

        // resCopy = resCopy->next;
        // for(;resCopy;){
        //     cout<<resCopy->val<<endl;
        //     resCopy = resCopy->next;
        // }

        head = resCopy->next;
        return;
    }
};

//寻找链表中点+链表逆序+合并链表
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }

        //获取链表中点
        ListNode *mid = midList(head);

        //反转链表后半段
        ListNode *l1 = head;
        ListNode *l2 = reverseList(mid);

        //合并链表
        mergeList(l1, l2);
    }

    //使用快慢指针，获取中点
    ListNode *midList(ListNode *head)
    {
        ListNode *slow = head, *fast = head;

        for (; fast->next != nullptr;)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next != nullptr)
            {
                fast = fast->next;
            }
        }

        return slow;
    }

    //反转链表
    ListNode *reverseList(ListNode *head)
    {
        ListNode *pre = nullptr, *cur = head;

        for (; cur != nullptr;)
        {
            ListNode *temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }

        return pre;
    }

    //合并链表
    void mergeList(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1;
        ListNode *temp2;

        for (; l1->next != nullptr && l2->next != nullptr;)
        {
            temp1 = l1->next;
            temp2 = l2->next;

            l1->next = l2;
            l1 = temp1;

            l2->next = l1;
            l2 = temp2;
        }
    }
};

/*
分析:   方法一： 使用线性表，记录顺序，一次插入重组
        方法二：寻找链表中点 + 链表逆序 + 合并链表，结合多种基础链表处理方法

方法:

总结:

*/