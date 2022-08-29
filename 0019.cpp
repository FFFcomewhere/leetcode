#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//获取长度 时间O(n) 空间O(1)
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *cur = dummy->next;
        int length = 0;
        for (; cur != nullptr;)
        {
            length++;
            cur = cur->next;
        }

        cur = dummy;
        for (int i = 0; i < length - n; i++)
        {
            cur = cur->next;
        }
        cur->next = cur->next->next;

        return dummy->next;
    }
};

//递归
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        return feedBack(dummy, n);
        return dummy->next;
    }

    ListNode *feedBack(ListNode *head, int &n)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        head = feedBack(head->next, n);
        n--;
        if (n == 0 && head->next != nullptr)
        {
            return head->next;
        }
        else
        {
            return head;
        }
    }
};

//stack
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        stack<ListNode *> s;

        ListNode *headCopy = head;
        for (; headCopy;)
        {
            s.push(headCopy);
            headCopy = headCopy->next;
        }

        ListNode *deleteNode;

        for (; !s.empty();)
        {
            n--;
            if (n == 0)
            {
                deleteNode = s.top();
                break;
            }
            s.pop();
        }

        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *temp = dummy;
        for (; temp != nullptr;)
        {
            if (temp->next != nullptr && temp->next == deleteNode)
            {
                temp->next = temp->next->next;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};

//双指针 快指针提起移动n步 快指针每次移动一步 慢指针每次移动一步
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy->next;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        for (; fast != nullptr;)
        {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
};

/*
分析:

方法:

总结:

*/