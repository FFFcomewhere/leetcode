#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<vector<int>> res;
        vector<int> sub_res;

        if (!root)
        {
            return res;
        }

        targetSum -= root->val;
        sub_res.emplace_back(root->val);
        feedBack(root, targetSum, res, sub_res);
        return res;
    }

    void feedBack(TreeNode *root, int targetSum, vector<vector<int>> &res, vector<int> &sub_res)
    {
        if (targetSum == 0 && root->left == nullptr && root->right == nullptr)
        {
            res.emplace_back(sub_res);
            return;
        }

        if (root == nullptr)
        {
            return;
        }

        if (root->left)
        {
            sub_res.emplace_back(root->left->val);
            feedBack(root->left, targetSum - root->left->val, res, sub_res);
            sub_res.pop_back();
        }

        if (root->right)
        {
            sub_res.emplace_back(root->right->val);
            feedBack(root->right, targetSum - root->right->val, res, sub_res);
            sub_res.pop_back();
        }

        return;
    }
};

/*
分析: dfs 找到退出条件

方法:

总结:

*/