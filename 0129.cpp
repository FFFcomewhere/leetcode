#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;

//DFS
class Solution {
private:
    int res;

public:
    int sumNumbers(TreeNode* root) {
        res = 0;
        dfs(root, 0);
        return res;
    }

    void feedBack(TreeNode* root, int cur) {
        if (root == NULL) {
            return ;
        }

        cur = cur * 10 + root->val;

        if (root->left == NULL && root->right == NULL) {
            res += cur;
        }
        feedBack(root->left, cur);
        feedBack(root->right, cur);
    }

    
};

//BFS
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        int res = 0;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            pair<TreeNode*, int> cur = q.front();
            q.pop();
            int curNum = cur.second * 10 + cur.first->val;
            if (cur.first->left == NULL && cur.first->right == NULL) {
                res += curNum;
            }
            if (cur.first->left != NULL) {
                q.push(make_pair(cur.first->left, curNum));
            }
            if (cur.first->right != NULL) {
                q.push(make_pair(cur.first->right, curNum));
            }
        }
        return res;
    }
};


/*
分析:

方法:

总结:

*/