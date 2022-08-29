#include <iostream>
#include <list>
#include <queue>
#include <vector>

using namespace std;

struct point
{
  int index;
  int length;

  point(int _index, int _length)
  {
    index = _index;
    length = _length;
  }
};

int n, m, src;
int dis[10], book[10], u[10], v[10], w[10];

int main()
{
  src = 1;
  cin >> n >> m;

  vector<list<point>> grid(n + 1);

  //初始化邻接表
  for (int i = 0; i < m; i++)
  {
    cin >> u[i] >> v[i] >> w[i];
    point temp(v[i], w[i]);
    grid[u[i]].push_back(temp);
  }

  //初始化距离数组
  for (int i = 1; i <= n; i++)
  {
    dis[i] = INT32_MAX;
  }

  dis[src] = 0;

  queue<int> q;
  q.push(src);

  //核心逻辑, 对已经达到最短路径的部分点出队, 减少计算量
  for (; q.size() != 0;)
  {
    int head = q.front();
    q.pop();
    book[head] = 1;
    for (int i = 1; i <= n; i++)
    {

      if (book[i] == 0 && dis[v[i]] != INT32_MAX && dis[u[i]] > dis[v[i]] + w[i])
      {
        q.push(v[i]);
        dis[u[i]] = dis[v[i]] + w[i];
      }
    }
  }

  for (int i = 1; i <= n; i++)
  {
    cout << dis[i] << " ";
  }
  cout << endl;
  return 0;
}

/*
5 5
2 3 2
1 2 -3
1 5 5 
4 5 2
3 4 3
*/