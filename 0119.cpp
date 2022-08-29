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

/*
分析: 找到数组键的关系

方法:　动态规划

总结:　无

*/