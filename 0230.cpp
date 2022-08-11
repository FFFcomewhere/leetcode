#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> stack;
        for (; root != nullptr || stack.size() > 0;)
        {
            for (; root != nullptr;)
            {
                stack.push(root);
                root = root->left;
            }
            root = stack.top();
            stack.pop();
            k--;
            if (k == 0)
            {
                break;
            }
            root = root->right;
        }
        return root->val;
    }
};


//优化 针对多次查找

class MyBst
{
public:
    TreeNode *root;

    MyBst(TreeNode *root)
    {
        root = root;
        countNodeCount(root);
    }

    int getNodeCount(TreeNode *node)
    {
        if (node != nullptr && nodeCount.count(node))
        {
            return nodeCount[node];
        }

        return 0;
    }

private:
    unordered_map<TreeNode *, int> nodeCount;

    int countNodeCount(TreeNode *node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        nodeCount[node] = countNodeCount(node->left) + countNodeCount(node->right) + 1;
        return nodeCount[node];
    }
};

class Solution
{
public:
    int kthSmallest(TreeNode *root, int k)
    {
        MyBst myBst(root);

        TreeNode *node = root;
        for (; node != nullptr;)
        {
            int leftNum = myBst.getNodeCount(node->left);

            if (leftNum > k - 1)
            {
                node = node->left;
            }
            else if (leftNum < k - 1)
            {
                node = node->right;
                k -= leftNum + 1;
            }
            else
            {
                break;
            }
        }
        return node->val;
    }
};

/*
分析:   每次都要寻找最小值，包括右子树
        方法二：针对多次查找，最好的办法就是将节点的子节点树储存下来，这样就不需要多次重复遍历前K个节点了

方法:

总结:

*/