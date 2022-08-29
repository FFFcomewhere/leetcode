#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <queue>
using namespace std;

//BFS
class Solution
{
public:
  int move_x[4] = {0, 0, 1, -1};
  int move_y[4] = {1, -1, 0, 0};

  vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
  {
    int n = image.size(), m = image[0].size();
    int curColor = image[sr][sc];

    if (n == 0 || m == 0)
    {
      return vector<vector<int>>{};
    }
    else if (curColor == newColor)
    {
      return image;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(sr, sc));
    image[sr][sc] = newColor;

    for (; q.size() != 0;)
    {
      int now_x = q.front().first, now_y = q.front().second;
      q.pop();

      for (int step = 0; step < 4; step++)
      {
        int new_x = now_x + move_x[step], new_y = now_y + move_y[step];

        if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < m && image[new_x][new_y] == curColor)
        {
          q.push(make_pair(new_x, new_y));
          image[new_x][new_y] = newColor;
        }
      }
    }

    return image;
  }
};

/*
分析: 图的遍历 可以使用BFS和DFS

方法:

总结:

*/