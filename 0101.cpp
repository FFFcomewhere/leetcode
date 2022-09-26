#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        //对称二叉树
        if(root == nullptr) {
            return true;
        }
        return feedBack(root->left, root->right);
    }

    bool feedBack(TreeNode* left, TreeNode* right){
        if(left == nullptr && right == nullptr) {
            return true;
        }
        if(left == nullptr || right == nullptr) {
            return false;
        }
        if(left->val != right->val) {
            return false;
        }
        return feedBack(left->left, right->right) && feedBack(left->right, right->left);
    }
};

/*
分析:

方法:

总结:

*/