#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> sub_res;
        feed_back(res, sub_res, candidates,target, candidates.size()-1);
        return res;
    }
    void feed_back(vector<vector<int>> &res, vector<int> &sub_res, vector<int> & candidates, int target, int start){
        if (target == 0){
            res.push_back(sub_res);
        }

        for(int i=start; i>=0; i--){
            if (target - candidates[i] < 0){
                continue;
            }
            sub_res.push_back(candidates[i]);
            feed_back(res, sub_res, candidates, target-candidates[i], i);
            sub_res.pop_back();
        }

    }
};

/*
分析: 毕竟目标值的题目，可以看出减法，同时对数组排序，既可以免去删去重复项的问题。

方法:  回溯+剪枝

总结:

*/