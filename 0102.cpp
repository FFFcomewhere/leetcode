#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> res;

        if (!root)
        {
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        for (; !q.empty();)
        {
            vector<int> sub_res;
            int length = q.size();
            for (int i = 0; i < length; i++)
            {
                auto data = q.front();
                q.pop();
                sub_res.push_back(data->val);

                if (data->left)
                {
                    q.push(data->left);
                }
                if (data->right)
                {
                    q.push(data->right);
                }
            }
            res.push_back(sub_res);
        }

        return res;
    }
};

//深度优先搜索
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {   
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        feedBack(1, root, res);
        return res;
    }

    void feedBack(int index, TreeNode *root, vector<vector<int>> &res)
    {
        if (res.size() < index)
        {
            vector<int> temp;
            res.emplace_back(temp);
        }

        res[index - 1].emplace_back(root->val);

        if (root->left)
        {
            feedBack(index + 1, root->left, res);
        }

        if (root->right)
        {
            feedBack(index + 1, root->right, res);
        }
    }
};

/*
分析: 广度优先搜索

方法:

总结:

*/