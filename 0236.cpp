#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//递归
class Solution
{
public:
    TreeNode *res;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        feedBack(root, q, p);
        return res;
    }

    bool feedBack(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (root == nullptr)
        {
            return false;
        }

        bool left = feedBack(root->left, p, q);
        bool right = feedBack(root->right, p, q);
        if ((left && right) || ((root->val == p->val || root->val == q->val) && (left || right)))
        {
            res = root;
        }

        return (left || right) || (root->val == p->val || root->val == q->val);
    }
};


//hash
class Solution
{
public:
    TreeNode *res;
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<int, TreeNode *> fa;
        unordered_map<int, bool> vis;
        fa[root->val] = nullptr;

        feedBack(root, fa);

        for (; p != nullptr;)
        {
            vis[p->val] = true;
            p = fa[p->val];
        }

        for (; q != nullptr;)
        {
            if (vis[q->val] == true)
            {
                return q;
            }
            q = fa[q->val];
        }
        return nullptr;
    }

    void feedBack(TreeNode *root, unordered_map<int, TreeNode *> &fa)
    {
        if (root == nullptr)
        {
            return;
        }

        if (root->left != nullptr)
        {
            fa[root->left->val] = root;
            feedBack(root->left, fa);
        }
        if (root->right != nullptr)
        {
            fa[root->right->val] = root;
            feedBack(root->right, fa);
        }
    }
};

/*
分析: 注意题目不是平衡二叉树，所以需要遍历到叶子节点，通过判断子树是否包含目标节点，确定是否为祖宗节点
        第一个满足条件的是最近祖宗节点。

方法:

总结:

*/