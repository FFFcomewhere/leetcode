#include <iostream>

using namespace std;
int n = 5, m = 8;

int grid[100][100];

int book[100];

int min_dis = INT32_MAX;

int tar = 4;
void dfs(int cur, int dis)
{

  if (dis > min_dis)
  {
    return;
  }

    if (cur == tar)
  {
    if (min_dis > cur)
    {
      min_dis = cur;
      return;
    }
  }

  for (int i = 0; i < 5; i++)
  {
    if (book[i] == 0 && grid[cur][i] != INT32_MAX)
    {
      book[i] = 1;
      dfs(i, dis + grid[cur][i]);
      book[i] = 0;
    }
  }
}

int main()
{

  for (int i = 0; i < 5; i++)
  {
    for (int j = 0; j < 5; j++)
    {
      grid[i][j] = INT32_MAX;
    }
  }

  grid[0][1] = 2;
  grid[0][5] = 10;
  grid[1][2] = 3;
  grid[1][4] = 7;
  grid[2][0] = 4;
  grid[2][3] = 4;
  grid[3][4] = 4;
  grid[4][2] = 3;

  book[0] = 1;
  dfs(0, 0);

  cout << "min_dis " << min_dis << endl;

  return 0;
}

/*
5 5 
1 2 2
1 5 10
2 3 3
2 5 7
3 1 4
3 4 4
4 5 5
5 3 3

*/