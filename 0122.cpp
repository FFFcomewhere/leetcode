#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//动态规划
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp[n][2];
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[n - 1][0];
    }
};

//动态规划 空间优化
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int dp0 = 0, dp1 = -prices[0];
        for (int i = 1; i < n; i++)
        {
            int Newdp0 = max(dp0, dp1 + prices[i]);
            int Newdp1 = max(dp1, dp0 - prices[i]);
            dp0 = Newdp0;
            dp1 = Newdp1;
        }

        return dp0;
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