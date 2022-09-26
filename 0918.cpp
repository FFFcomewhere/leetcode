#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        //分两种情况 答案在中间 答案在两端
        int dp0 = nums[0], _max = nums[0];
        int dp1 = nums[0], _min = nums[0];
        int sum = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(dp0>0){
                dp0 = dp0 + nums[i];
            } else {
                dp0 = nums[i];
            }

            if(dp1<0){
                dp1 = dp1 + nums[i];
            } else {
                dp1 = nums[i];
            }

            _max = max(_max, dp0);
            _min = min(_min, dp1);
            sum+=nums[i];
        }

        if(sum - _min == 0){
            return _max;
        }

        return max(_max, sum-_min);
    }


};

/*
分析:

方法:

总结:

*/