#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//动态规划 时间O(mn) 空间O(1)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //中规中矩的动态规划 二维动态规划 可以优化为一维
        //dp[i][j] 为(i,j)位置上的最小路径
        //dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + nums[i][j] for i>=1,j>=1
        //dp[0][j] = dp[i][0] = 0

        int m = grid.size(), n = grid[0].size();

        for(int i=1; i<m; i++){
            grid[i][0] += grid[i-1][0] ;
        }
        for(int j=1; j<n; j++){
            grid[0][j] += grid[0][j-1];
        }       

        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
            }
        }

        return grid[m-1][n-1];
    }
};

/*
分析:

方法:

总结:

*/