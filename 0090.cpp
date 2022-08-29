#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> sub_res;
        feed_back(res, sub_res, nums, 0);
        return res;
    }

    void feed_back(vector<vector<int>> &res, vector<int> &sub_res, vector<int> & nums, int start){
        res.push_back(sub_res);

        for(int i=start; i<nums.size(); i++){
            if(i > start && nums[i] == nums[i-1]){
                continue;
            }
            sub_res.push_back(nums[i]);
            feed_back(res, sub_res, nums, i+1);
            sub_res.pop_back();
        }
    }
};

/*
分析: 是一个子集问题，可以很明显看出，使用回溯算法，但是元素里有重复项，
        先使用排序算法，然后对于重复元素的枝节点，过滤

方法:  回溯 + 剪枝

总结: 

*/