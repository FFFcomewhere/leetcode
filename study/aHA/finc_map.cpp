#include <iostream>
#include <vector>
using namespace std;

int move_x[4] = {0, 0, 1, -1};
int move_y[4] = {1, -1, 0, 0};
int min_step = 9999;

void dfs(vector<vector<int>> &graph, int x, int y, int tar_x, int tar_y, int step)
{
  if (x == tar_x && y == tar_y)
  {
    if (min_step > step)
    {
      min_step = step;
    }
    return;
  }

  for (int i = 0; i < 4; i++)
  {
    int new_x = x + move_x[i];
    int new_y = y + move_y[i];

    if (new_x >= 0 && new_x < graph.size() && new_y >= 0 && new_y < graph[0].size() && graph[new_x][new_y] == 0)
    {
      graph[new_x][new_y] = -1;
      dfs(graph, new_x, new_y, tar_x, tar_y, step + 1);
      graph[new_x][new_y] = 0;
    }
  }
}

int main()
{
  vector<vector<int>> graph{
      {0, 0, 1, 1},
      {0, 0, 0, 0},
      {0, 1, 0, 0},
      {0, 1, 0, 0},
      {0, 0, 0, 1}};

  int src_x = 0, src_y = 0, tar_x = 3, tar_y = 2;
  int step = 0;
  dfs(graph, src_x, src_y, tar_x, tar_y, step);
  cout << min_step << endl;

  return 0;
}