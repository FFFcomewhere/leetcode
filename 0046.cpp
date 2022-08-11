#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//DFS
class Solution
{
public:
    vector<vector<int>> res;
    vector<int> subRes;
    vector<int> book;
    vector<vector<int>> permute(vector<int> &nums)
    {
        int n = nums.size();

        subRes.resize(n);
        book.resize(n);
        feedBack(nums, 0, n);

        return res;
    }

    void feedBack(vector<int> &nums, int now, int size)
    {
        if (now == size)
        {
            res.emplace_back(subRes);
            return;
        }

        for (int i = 0; i < size; i++)
        {
            if (book[i] == 0)
            {
                book[i] = 1;
                subRes[now] = nums[i];
                feedBack(nums, now + 1, size);
                subRes[now] = nums[i];
                book[i] = 0;
            }
        }

        return;
    }
};


/*
分析: 这是一个全排列问题，所以需要按顺序调用元素，同时元素是不重复的
    所以需要记录元素是否使用。

方法: 回溯

总结:

*/