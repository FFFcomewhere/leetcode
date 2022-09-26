#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows);
    
        if(numRows == 1) return {{1}};

        for(int i=0; i<numRows; i++) {
            dp[i] = vector<int>(i+1, 1);
        }

        for(int i=2; i<numRows; i++){
            for(int j=1; j<i; j++){
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
        return dp;
    }
};

/*
分析:

方法:

总结:

*/