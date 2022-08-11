#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//使用数组存储，时间On 空间0n
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    vector<ListNode *> data;
    ListNode *headCopy = head;
    for (; headCopy != nullptr;)
    {
      data.emplace_back(headCopy);
      headCopy = headCopy->next;
    }

    ListNode *res = nullptr;
    ListNode *resCopy = res;
    for (int i = 0; i < data.size(); i++)
    {
      data[i]->next = resCopy;
      resCopy = data[i];
    }

    return resCopy;
  }
};

//双指针 迭代   时间On 空间01
class Solution
{
public:
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
};

//递归  时间On 空间On
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr || head->next == nullptr)
    {
      return head;
    }

    ListNode *temp = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return temp;
  }
};

//头插法 时间On 空间O1
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    if (head == nullptr)
    {
      return nullptr;
    }
    ListNode *cur = head;

    for (; head->next != nullptr;)
    {
      ListNode *temp = head->next->next;
      head->next->next = cur;
      cur = head->next;
      head->next = temp;
    }

    return cur;
  }
};

/*
分析:   反转链表 双指针：
        1.用pre和cur指针，pre指向nullptr，cur指向head；
        2.用temp指针，temp指向cur的下一个节点；
        3.cur的next指向pre；
        4.pre和cur指针向前移动一位；
        5.重复步骤3和4，直到cur指向nullptr；
        6.pre指向的节点就是反转后的链表的头节点。

        递归
        1.当cur为nullptr时，返回pre；
        2.递归后继节点，已反转
        3.修改当前节点指针指向
        4.返回反转后的链表的头节点

方法: 双指针；递归

总结:

