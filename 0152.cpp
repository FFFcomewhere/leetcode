#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

//动态规划  正负数分类讨论
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxDp(nums), minDp(nums);

        for(int i=1; i<n; i++){
            maxDp[i] = max(maxDp[i-1]*nums[i], max(minDp[i-1]*nums[i], nums[i]));
            minDp[i] = min(minDp[i-1]*nums[i], min(maxDp[i-1]*nums[i], nums[i]));
        }
        
        return *max_element(maxDp.begin(), maxDp.end());
    }
};


//动态规划 进行了空间优化
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int _max = nums[0], _min = nums[0], res = nums[0];

        for(int i=1; i<nums.size(); i++){
            int tempMax = _max, tempMin = _min; 
            _max = max(_max*nums[i], max(_min*nums[i], nums[i]));
            _min = min(_min*nums[i], min(tempMax*nums[i], nums[i]));
            res = max(res, _max);
        }
        
        return res;
    }
};

/*
分析:

方法:

总结:

*/