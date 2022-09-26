#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) {
            return true;
        }

        if(root->left != nullptr && root->left->val >= root->val){
            return false;
        }

        if(root->right != nullptr && root->right->val <= root->val){
            return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};

int main() {
    Solution s;
    s.isValidBST(nullptr);
    return 0;
}
/*
分析:

方法:

总结:

*/