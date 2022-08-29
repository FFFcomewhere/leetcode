#include <iostream>

using namespace std;

int dis[10], u[10], v[10], w[10]; //源点到其他点的距离, 起始点坐标, 终点坐标,  边长

int n, m, src;

int main()
{
  cin >> n >> m;

  src = 1;
  //初始化化数组
  for (int i = 1; i <= m; i++)
  {
    cin >> u[i] >> v[i] >> w[i];
  }

  //初始标定数组
  for (int i = 1; i <= n; i++)
  {
    dis[i] = INT32_MAX;
  }
  dis[src] = 0;

  //可以剪枝 !!!
  int check = 1;

  //核心算法  每次遍历相当于 只经过k条边,到达其他点的最短路径,对于n个点来说, 最多n-1个点
  for (int k = 1; k < n; k++)
  {
    check = 0;

    // 遍历每条边  进行松弛操作
    for (int i = 1; i <= m; i++)
    {
      if (dis[u[i]] != INT32_MAX && dis[v[i]] > dis[u[i]] + w[i])
      {
        dis[v[i]] = dis[u[i]] + w[i];
        check = 1;
      }
    }

    if (check == 0)
    {
      break;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    cout << dis[i] << " ";
  }
  cout << endl;
}

/*
5 5
2 3 2
1 2 -3
1 5 5 
4 5 2
3 4 3
*/