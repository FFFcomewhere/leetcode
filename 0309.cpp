#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(3, 0));
        dp[0][0] = dp[0][1] = 0;
        dp[0][2] = -prices[0];

        for(int i=1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], dp[i-1][2]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][2] = max(dp[i-1][2], dp[i-1][1]-prices[i]);
        }

        return max(dp[n-1][0], dp[n-1][1]);
    }
};

//空间优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {        
        int dpThrow=0, dpFreez = 0;
        int dpHold = -prices[0];

        for(int i=1; i<prices.size(); i++){
            int tempThrow = dpThrow, tempFreez = dpFreez, tempHold = dpHold;

            dpThrow = max(tempThrow, tempHold+prices[i]);
            dpFreez = max(tempFreez, tempThrow);
            dpHold = max(tempHold, tempFreez-prices[i]);
        }

        return max(dpThrow, dpFreez);
    }
};

/*
分析: 将三种状态分别表示为 0:不持有股票 1:冷冻期 2:持有股票


方法:

总结:

*/