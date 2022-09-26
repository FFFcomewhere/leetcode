#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  vector<int> getRow(int rowIndex)
  {
    if (rowIndex == 0)
    {
      return {1};
    }
    else if (rowIndex == 1)
    {
      return {1, 1};
    }

    vector<int> up(rowIndex + 1);
    up[0] = 1;
    up[1] = 1;

    for (int i = 2; i <= rowIndex; i++)
    {
      vector<int> down(i + 1);
      down[0] = down[i] = 1;

      for (int j = 1; j < i; j++)
      {
        down[j] = up[j - 1] + up[j];
      }
      up = down;
    }
    return up;
  }
};


//空间优化0.1
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
    
        if(rowIndex < 2) return dp;

        for(int i=2; i<=rowIndex; i++){
            vector<int> lastDp = dp;
            for(int j=1; j<i; j++){
              dp[j] = lastDp[j-1] + lastDp[j];
            }
        }
        return dp;
    }
};

//空间优化0.2
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp(rowIndex+1, 1);
    
        if(rowIndex < 2) return dp;

        for(int i=2; i<=rowIndex; i++){
            int dp0 = dp[1], dp1 = dp[2];
            for(int j=1; j<i; j++){
              int temp = dp[j];
              dp[j] = dp0 + dp1;
              dp0 = dp1;
              dp1 = temp;
            }
        }
        return dp;
    }
};

/*
分析: 找到数组键的关系

方法:　动态规划

总结:　无

*/