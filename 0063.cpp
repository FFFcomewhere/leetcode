#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//dp 注意障碍物对dp数组的影响
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));

        for(int i=0; i<m; i++){
            if(obstacleGrid[i][0] == 1){
                break;
            }
            dp[i][0] = 1;
        } 

        for(int j=0; j<n; j++){
            if(obstacleGrid[0][j] == 1){
                break;
            }
            dp[0][j] = 1;
        }

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[i][j] = 0;
                }  else {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[m-1][n-1];
    }
};

//空间压缩
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(), n=obstacleGrid[0].size();
        vector<int> dp(n, 0);

        dp[0] = (obstacleGrid[0][0] == 0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1){
                    dp[j] = 0;
                    continue;
                } 
                
                if(j-1 >=0 && obstacleGrid[i][j-1] == 0){
                    dp[j] += dp[j-1];
                } 
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