#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
private:
    int res;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        feedBack(root);
        return res;
    }

    int feedBack(TreeNode* root) {
        if(root == nullptr){
            return 0;
        }
        
        int L = feedBack(root->left);
        int R = feedBack(root->right);

        res = max(res, L+R);
        return max(L+1, R+1);
    }
};

/*
分析:

方法:

总结:

*/