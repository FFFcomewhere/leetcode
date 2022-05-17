#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> sub_res;

        feed_back(res, sub_res, nums, 0);
        return res;
    }

    void feed_back(vector<vector<int>> &res, vector<int> &sub_res, vector<int> &nums, int index)
    {
        res.push_back(sub_res);

        for (int i = index; i < nums.size(); i++)
        {
            sub_res.push_back(nums[i]);
            feed_back(res, sub_res, nums, i + 1);
            sub_res.pop_back();
        }
    }
};

/*
分析: 回溯问题


方法: 回溯

总结:
 流程分析：
    1.画递归树，找到状态变量（形参）！
    2.确认结束条件
    3.找选择列表，即循环条件
    4.做出选择，递归调用
    5.取消选择

*/