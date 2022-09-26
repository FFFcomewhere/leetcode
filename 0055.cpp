#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int rightMost = 0;
        for(int i=0; i<n; i++){ 
            if(i <= rightMost){
                rightMost = max(rightMost, i+nums[i]);
                if(rightMost >= n-1){
                    return true;
                }
            }
        }

        return false;
    }
};


class Solution {
public:
    bool canJump(vector<int>& nums) {
        int _max = 0;
        for(int i=0; i<nums.size(); i++){
            if(i > _max){
                return false;
            }
            _max = max(_max, i+nums[i]);
        }

        return true;
    }
};


//动态规划 未经过优化
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1){
            return true;
        }

        vector<bool> dp(n, false);
        dp[0] = true;
        if(nums[0]>0){
            dp[1] = true;
        }

        for(int i=2; i<n; i++){
            for(int j=i-1; j>=0; j--){
                if(dp[j] == true && nums[j]+j >= i){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n-1];
    }
};

/*
分析: 这是一个最远目标问题，只要最远能跳到的地方超过目标点，就认为可以到达
 
方法: 贪心算法

总结: 针对这种最远和最近可到达，可以使用贪心

*/