#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> sub_res;
        vector<int> book(nums.size(), 0);
        feed_back(res, sub_res, nums, book, 0);
        return res;
    }

    void feed_back(vector<vector<int>> &res, vector<int> &sub_res, vector<int> &nums, vector<int> book, int start){
        if (start >= nums.size()){
            res.push_back(sub_res);
            return ;
        }

        for(int i = 0; i < nums.size(); i++){
            if(book[i] == 0)
            {   
                book[i] = 1;
                sub_res.push_back(nums[i]);
                feed_back(res, sub_res, nums, book, start+1);
                sub_res.pop_back();  
                book[i] = 0;
            }
        }       
    }
};

/*
分析: 这是一个全排列问题，所以需要按顺序调用元素，同时元素是不重复的
    所以需要记录元素是否使用。

方法: 回溯

总结:

*/