#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


//记忆化搜索
class Solution {
public:
    vector<int> data;
    int coinChange(vector<int>& coins, int amount) {
        if(coins.size() == 0){
            return -1;
        }
        data.resize(amount);

        return feedBack(coins, amount);
    }

    int feedBack(vector<int>& coins, int amount){
        if(amount < 0){
            return -1;
        }
        if(amount == 0){
            return 0;
        }

        if(data[amount-1] != 0){
            return data[amount-1];
        }

        int _min = INT_MAX;
        for(auto e : coins){
            int res = feedBack(coins, amount-e);
            if(res >= 0 && res <_min){
                _min = res+1;
            }
        }

        if(_min == INT_MAX){
            data[amount-1] = -1;
        } else {
            data[amount-1] = _min;
        }
        return data[amount-1];
    }
};

//动态规划的思想 
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if(n == 0){
            return -1;
        }

        int _max = amount+1;
        vector<int> dp(amount+1, _max);
        dp[0] = 0;
        for(int i=1; i<=amount; i++){
            for(int j=0; j<n; j++){
                if(coins[j]<=i){
                    dp[i] = min(dp[i], dp[i-coins[j]]+1);
                }
            }
        }
        
        if(dp[amount]>amount){
            return -1;
        } else {
            return dp[amount];
        }
    }
};


/*
分析:

方法:

总结:

*/