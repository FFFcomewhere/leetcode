#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//遍历 O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> postivity;

        for(;head != nullptr;){
            postivity.push_back(head->val);
            head = head->next;
        }
        int n = postivity.size();
        for(int i=0; i<n; i++){
            if (postivity[i] != postivity[n-1-i]){
                return false;
            }
        }

        return true;
    }
};

//反转链表 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        //find mid 
        ListNode *slow = head, *fast = head;

        for(;fast->next && fast->next->next;){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* rList = reverseList(slow->next);
         
        for(;rList;) {
            if(head->val != rList->val){
                return false;
            } else {
                
                head = head->next;
                rList = rList->next;
            }
        }
        
        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr, *cur = head;

        for(;cur != nullptr;) {
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }
};

/*
分析:

方法:

总结:

*/