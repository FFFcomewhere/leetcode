#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;


class Solution
{
public:
  void rotate(vector<vector<int>> &matrix)
  {
    int n = matrix.size();
    auto newMatrix = matrix;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        newMatrix[j][n - i - 1] = matrix[i][j];
      }
    }
    matrix = newMatrix;

    return;
  }
};


// 法二，旋转 拆分为翻转和对折
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                swap(matrix[i][j], matrix[n-1-i][j]);
            }
        }

 
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }       
        return;
    }
};


/*
分析: 辅助数组，可以看出新数组位置和旧数组位置的关系NM[j][n-i-1] = M[i][j]； 
          将选择转化为翻转，旋转必定需要额外的空间，将旋转关系式拆分为翻转关系式：即
          M[n-i-1][j] = M[i][j]
          M[j][n-i-1][j] = M[j][n-i-1]

方法:　辅助数组;　　旋转转化为翻转

总结:　找规律

*/