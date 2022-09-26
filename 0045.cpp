#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//动态规划 时间O(n^2) 空间O(n)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        //记录每个到底i点 最少需要多少步
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;

        for(int i=1; i<n; i++){
            int _min = INT_MAX;
            for(int j=i-1; j>=0; j--){
                //能跳到i的最小次数
                if(_min > dp[j] && j+nums[j] >= i){
                    _min = dp[j];
                }
            }

            dp[i] = _min+1;
        }

        return dp[n-1];
    }
};


//贪心算法 时间O(n) 空间O(1) 本质上还是最远距离，但是这里需要维护两个边界
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int res = 0;
        int oldEnd = 0;
        int newEnd = 0;
        for(int i=0; i<n-1; i++){
            newEnd = max(newEnd, i+nums[i]);
            if(i == oldEnd){
                oldEnd = newEnd;
                res++;
            }
        }

        return res;
    }
};

/*
分析:

方法:

总结:

*/