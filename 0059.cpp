#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  //右　下　左　上
  int move_x[4] = {0, 1, 0, -1};
  int move_y[4] = {1, 0, -1, 0};

  vector<vector<int>> generateMatrix(int n)
  {
    int row = 0, column = 0;
    int num = 0;
    int max_num = n * n;
    int step = 0;
    vector<vector<int>> res(n, vector<int>(n));
    res[0][0] = ++num;
    for (; num < max_num;)
    {
      step = step % 4;
      int new_row = row + move_x[step];
      int new_column = column + move_y[step];
      if (new_row >= 0 && new_row < n && new_column >= 0 && new_column < n &&
          res[new_row][new_column] == 0)
      {
        row = new_row;
        column = new_column;
        res[row][column] = ++num;
      }
      else
      {
        step++;
      }
    }

    return res;
  }
};

/*
分析: 观察规律，模拟插入的方式

方法:　模拟

总结:　无

*/