#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//动态规划
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][0]-prices[i], dp[i-1][1]);
        }
        return dp[n-1][0];
    }
};
//动态规划 空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int dpThrow = 0, dpGet = 0;
        dpThrow = 0;
        dpGet = -prices[0];

        for(int i=1; i<n; i++){
            int tempThrow = dpThrow, tempGet = dpGet;
            dpThrow = max(tempThrow, tempGet+prices[i]);
            dpGet = max(tempThrow-prices[i], tempGet);
        }
        return dpThrow;
    }
};


//贪心算法
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++)
        {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};

/*
分析:  法一：动态规划，找到状态转移方程
        法二：贪心，可以看做求不相交区间最大和，等价与求每个间隔为1的区间的最大和，即max(0, num[i]-num[i-1])

方法:

总结:

*/