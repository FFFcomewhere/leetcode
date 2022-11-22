#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

/*使用动态规划
关键是找到规律，这里将每一列的图案分为四种情况讨论。
*/

class Solution {
public:
    int numTilings(int n) {
        vector<vector<long>> dp(n+1, vector<long>(4, 0));
        long Mod = 1e9+7;
        dp[1][0] = dp[1][1] = 1;

        for(int i=2; i<=n; i++){
            dp[i][0] = dp[i-1][1];

            long temp=0;
            for(int j=0; j<4; j++){
                temp = (temp+dp[i-1][j]) % Mod;
            }

            dp[i][1] = temp;
            dp[i][2] = dp[i-1][0]+dp[i-1][3];
            dp[i][3] = dp[i-1][0]+dp[i-1][2];
        }

        return dp[n][1];
    }
};

/*
分析:

方法:

总结:

*/