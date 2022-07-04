#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


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

/*
分析:   使用unordered_set来记录节点，如果节点已经存在，则说明有环，返回该节点。


方法:   哈希表

总结:   

*/