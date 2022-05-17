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


/*
分析:

方法:

总结:

*/