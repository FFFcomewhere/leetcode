#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){} ;
     ListNode(int x) : val(x), next(nullptr){} ;
    ListNode(int x, ListNode *next) : val(x), next(next){};                                                                                                                                   *
};

//hash
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        unordered_map<int, int> h;
        int data[400];
        int index = 1;
        for (; head != nullptr;)
        {
            if (h[head->val] != 0)
            {
                data[h[head->val]] = -300;
            }
            else
            {
                h[head->val] = index;
                data[index] = head->val;
                index++;
            }
            head = head->next;
        }

        ListNode *res = new ListNode;
        ListNode *copy_res = res;
        for (int i = 1; i < index; i++)
        {
            if (data[i] == -300)
            {
                continue;
            }
            ListNode *new_node = new ListNode;
            new_node->val = data[i];
            copy_res->next = new_node;
            copy_res = copy_res->next;
        }

        return res->next;
    }
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode *preHead = new ListNode;
        preHead->next = head;
        ListNode *pre = preHead;
        ListNode *cur = head;

        for (; cur != nullptr;)
        {

            for (; cur->next && cur->val == cur->next->val;)
            {
                cur = cur->next;
            }

            if (pre->next == cur)
            {
                pre = pre->next;
            }
            else
            {
                pre->next = cur->next;
            }
            cur = cur->next;
        }

        return preHead->next;
    }
};

/*
分析: 快慢指针，对于相同元素，循环遍历到元素不同位置；但是注意第一个节点前要加一个哑节点，防止第一个元素删除后，没有头结点。

方法:   快慢指针

总结:

*/