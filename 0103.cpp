#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool order = true;

        vector<vector<int>> res;

        if(!root){
            return res;
        }

        queue<TreeNode *> q;
        q.push(root);

        for(;!q.empty();){
            deque<int> sub_res;
            int length = q.size();

            for(int i = 0; i<length; i++){
                auto node = q.front();
                q.pop();

                if(order == true){
                    sub_res.push_back(node->val);
                } else {
                    sub_res.push_front(node->val);
                }

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }    
                
            }

            if(order == false){
                order= true;
            } else {
                order= false;
            }

            res.emplace_back(vector<int>{sub_res.begin(), sub_res.end()});
        }
        return res;
    }

};

//dfs
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<deque<int>> TempRes;
        if (root == nullptr)
        {
            return {};
        }
        feedBack(1, true, root, TempRes);

        int n = TempRes.size();
        vector<vector<int>> res(n);
        for (int i = 0; i < n; i++)
        {
            res[i] = vector<int>{TempRes[i].begin(), TempRes[i].end()};
        }
        return res;
    }

    void feedBack(int index, bool order, TreeNode *root, vector<deque<int>> &res)
    {
        if (res.size() < index)
        {
            res.emplace_back(deque<int>{});
        }

        if (order == true)
        {
            res[index - 1].push_back(root->val);
        }
        else
        {
            res[index - 1].push_front(root->val);
        }

        if (root->left)
        {
            feedBack(index + 1, !order, root->left, res);
        }
        if (root->right)
        {
            feedBack(index + 1, !order, root->right, res);
        }
    }
};

/*
分析: 广度优先搜索，和102题一样，但是注意反转方向

方法:

总结:

*/