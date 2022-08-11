#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//递归
class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return feedBack(nums, 0, nums.size() - 1);
    }

    TreeNode *feedBack(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }

        int mid = (l + r + rand() % 2) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        root->left = feedBack(nums, l, mid - 1);
        root->right = feedBack(nums, mid + 1, r);
        return root;
    }
};

/*
分析:   注意题目的已知条件，排好序，所以可以最直接使用中序排序

方法:

总结:

*/