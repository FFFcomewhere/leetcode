#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int res = INT_MIN;
    int maxPathSum(TreeNode* root) {
        //分析找到了最优子结构（求根节点的左右子树和）和重复子问题（每个根节点会重复计算）
        //可以使用记忆化搜索的方法，把最大路径和存储在根节点上
        //注意：存储在根节点上的只能是左右子树之一，保证可以连通父节点；使用_max记录最大值
        feedBack(root);
        return res;
    }

    int feedBack(TreeNode* root){
        if(root == nullptr){
            return 0;
        }

        int left = max(feedBack(root->left), 0);
        int right = max(feedBack(root->right), 0);

        res = max(res, root->val+left+right);
        
        return root->val+max(left, right);
    }
};

/*
分析:

方法:

总结:

*/