#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
private:
    vector<vector<int>>  res;
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> subRes;
        feedBack(root, subRes, targetSum);
        return res;
    }

    void feedBack(TreeNode* root, vector<int> &subRes, int targetSum) {
        if(root == nullptr) {
            return;
        }

        subRes.emplace_back(root->val);
        targetSum-=root->val;

        if(root->left == nullptr && root->right == nullptr && targetSum == 0){
            res.emplace_back(subRes);
        }

        feedBack(root->left, subRes, targetSum);
        feedBack(root->right, subRes, targetSum);
        subRes.pop_back();
        return;
    }
};
/*
分析: dfs 找到退出条件

方法:

总结:

*/