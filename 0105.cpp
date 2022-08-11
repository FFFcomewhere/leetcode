#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//递归
class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return feedBack(preorder, 0, preorder.size() - 1,
                        inorder, 0, inorder.size() - 1);
    }

    TreeNode *feedBack(vector<int> &preorder, int preLeft, int preRight,
                       vector<int> &inorder, int inLeft, int inRight)
    {
        if (preLeft > preRight)
        {
            return nullptr;
        }

        TreeNode *root = new TreeNode(preorder[preLeft]);

        int loc_root = distance(inorder.begin(), find(inorder.begin(), inorder.end(), preorder[preLeft]));
        int left_num = loc_root - inLeft;

        root->left = feedBack(preorder, preLeft + 1, preLeft + left_num,
                              inorder, inLeft, loc_root - 1);

        root->right = feedBack(preorder, preLeft + left_num + 1, preRight,
                               inorder, loc_root + 1, inRight);

        return root;
    }
};

/*
分析: 注意前序遍历 和 中序遍历的关系

方法:

总结:

*/