#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//dp 时间mn, 空间mn
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            dp[i][0] = 1;
        } 

        for(int j=0; j<n; j++){
            dp[0][j] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        return dp[m-1][n-1];
    }
};


//空间优化 时间mn 空间n
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1); 

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                dp[j] += dp[j-1];
            }
        }

        return dp[n-1];
    }
};
/*
分析:

方法:

总结:

*/