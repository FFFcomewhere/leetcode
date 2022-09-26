#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//常规的dp
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=1; i<n; i++){
            for(int j=0; j<n; j++){
                int _min=matrix[i-1][j];
                if(j>0) {
                    _min=min(_min, matrix[i-1][j-1]);
                }
                if(j<n-1) {
                    _min=min(_min, matrix[i-1][j+1]);
                }
                matrix[i][j]+=_min;
            }
        }

        int _min = matrix[n-1][0];
        for(int i=0; i<n; i++){
            _min = min(_min, matrix[n-1][i]);
        }
        return _min;
    }
};

/*
分析:

方法:

总结:

*/