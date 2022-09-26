#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        //关键点 头结点是否偷
        //dp[i] 含义：偷到第i间房间做到的钱
        //dp[i] = max(dp[i-2]+nums[i], dp[i-1]); 注意 是否偷第一个节点,分两种情况考虑
        //dp[0] = nums[0], dp[1] = max(nums[0], nums[1])


        int n  = nums.size();

        if(n == 1){
            return nums[0];
        } else if(n == 2){
            return max(nums[0], nums[1]);
        }

        return max(getRes(nums, 0, n-1), getRes(nums, 1, n));
    }

    int getRes(vector<int>& nums, int beg, int end){
        vector<int> dp(end, 0);
        dp[beg] = nums[beg];
        dp[beg+1] = max(nums[beg], nums[beg+1]);

        for(int i=beg+2; i<end; i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }

        return dp[end-1];
    }
};

/*
分析:  

方法:

总结:

*/