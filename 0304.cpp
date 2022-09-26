#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//二位前缀和
class NumMatrix {
private:
    vector<vector<int>> matrix;
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        matrix = matrix;
        int m=matrix.size(), n = matrix[0].size();
        //计算二维前缀和
        preSum.resize(m+1);
        preSum.assign(m+1, vector<int>(n+1, 0));

        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                    preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] + matrix[i-1][j-1] - preSum[i-1][j-1];
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preSum[row2+1][col2+1] - preSum[row2+1][col1] 
                - preSum[row1][col2+1] + preSum[row1][col1];
    }
};



/*
分析:

方法:

总结:

*/