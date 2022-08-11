#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr){
            return nullptr;
        }     

        if(root->val > key){
            root->left = deleteNode(root->left, key);
            return root;
        }

        if(root->val < key){
            root->right = deleteNode(root->right, key);
            return root;
        }

        if(root->val == key){
            if(root->left == nullptr && root->right == nullptr){
                return nullptr;
            } else if(root->left == nullptr){
                return root->right;
            } else if(root->right == nullptr){
                return root->left;
            }
            TreeNode* successor = root->right;
            while (successor->left) {
                successor = successor->left;
            }
            root->right = deleteNode(root->right, successor->val);
            successor->right = root->right;
            successor->left = root->left;
            return successor;
        }
        return root;
    }
};


/*
分析: 对于二叉平衡树，使用递归，注意判断条件


方法:

总结:

*/