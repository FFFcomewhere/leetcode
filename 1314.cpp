#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(), n = mat[0].size();
        //计算二维前缀和
        vector<vector<int>> preSum(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                    preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + mat[i-1][j-1] - preSum[i-1][j-1];
            }
        }

        vector<vector<int>> res(m, vector<int>(n, 0));
        //计算每个点的扩散范围，即左上角和右下角坐标
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int row1 = max(1, i-k+1), colums1 = max(1, j-k+1);
                int row2 = min(m, i+k+1), colums2 = min(n, j+k+1);
                res[i][j] = preSum[row2][colums2] - preSum[row2][colums1-1] 
                            - preSum[row1-1][colums2] + preSum[row1-1][colums1-1];
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