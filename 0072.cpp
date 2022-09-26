#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m==0 || n==0) {
            return m+n;
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        for(int i=0; i<=n; i++){
            dp[0][i] = i;
        }

        for(int i=0; i<=m; i++){
            dp[i][0] = i;
        }

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                int left_down = dp[i-1][j-1];
                if(word1[i-1] != word2[j-1]){
                    left_down++;
                }

                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), left_down);
            }
        }
        
        return dp[m][n];
    }
};

/*
分析: 动态规划 先搞清楚dp[i][j]的定义，dp[i][j]表示word1的前i个字符和word2的前j个字符的最小编辑距离
      然后找出状态转移方程，dp[i][j] = min(dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1) 1表示插入，2表示删除，3表示替换
      最后找出初始状态，dp[0][j] = j, dp[i][0] = i

方法:

总结:

*/