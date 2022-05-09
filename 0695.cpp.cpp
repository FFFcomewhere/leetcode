#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  int max_eara = 0;
  int move_x[4] = {0, 0, 1, -1};
  int move_y[4] = {1, -1, 0, 0};

  int maxAreaOfIsland(vector<vector<int>> &grid)
  {

    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        if (grid[i][j] == 1)
        {
          int eara = 0;
          dfs(grid, i, j, eara);
        }
      }
    }

    return max_eara;
  }

  void dfs(vector<vector<int>> &grid, int x, int y, int &eara)
  {
    if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] != 1)
    {
      return;
    }

    eara++;
    if (max_eara < eara)
    {
      max_eara = eara;
    }

    for (int i = 0; i < 4; i++)
    {
      dfs(grid, x + move_x[i], y + move_y[i], eara);
    }

    return;
  }
};

/*
分析: 图的遍历,可以使用bfs和dfs

方法: bfs dfs

总结: 统计值

*/