#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 0);
        int lastSub = 0;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                if(lastSub==0){
                    lastSub = i;
                }
                dp[i] = dp[i-1]+1+(i-lastSub);
            } else {
                lastSub = 0;
                dp[i] = dp[i-1];
            }
        }
        return dp[n-1];
    }
};


//空间优化
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int dp = 0;
        int lastSub = 0;
        for(int i=2; i<nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]){
                if(lastSub==0){
                    lastSub = i;
                }
                dp = dp+1+(i-lastSub);
            } else {
                lastSub = 0;
                dp = dp;
            }
        }
        return dp;
    }
};

/*
分析: 动态规划 注意添加判断原来是否为等差数列

方法:

总结:

*/