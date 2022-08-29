#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//动态规划
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 0, length = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }

        return res;
    }
};


//动态规划+二分查找 本质上在寻找尽可能小的数字
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int res = 0;

        for (auto num : nums)
        {
            int i = 0, j = res;
            for (; i < j;)
            {
                int m = (j - i) / 2 + i;
                if (dp[m] < num)
                {
                    i = m + 1;
                }
                else
                {
                    j = m;
                }
            }
            dp[i] = num;
            if (res == j)
            {
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