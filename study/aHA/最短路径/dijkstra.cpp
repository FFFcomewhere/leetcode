#include <iostream>

using namespace std;

int grid[10][10];
int dis[10], book[10];

int n, m, src;

int main()
{
	cin >> n >> m;

	src = 1;
	//初始化矩阵
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
			{
				grid[i][j] = 0;
				continue;
			}
			grid[i][j] = INT32_MAX;
		}
	}

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		cin >> grid[x][y];
	}

	//初始标定数组
	for (int i = 1; i <= n; i++)
	{
		dis[i] = grid[src][i];
		book[i] = 0;
	}
	book[src] = 1;

	//核心算法   通过点, 进行松弛操作, 找到最近点, 然后缩短和其他点的距离
	for (int i = 1; i < n; i++)
	{

		//找到距离最近的点
		int _min = INT32_MAX;
		int u = 0;
		for (int k = 1; k <= n; k++)
		{
			if (book[k] == 0 && _min > dis[k])
			{
				_min = dis[k];
				u = k;
			}
		}

		book[u] = 1;
		//进行松弛操作
		for (int j = 1; j <= n; j++)
		{
			if (grid[u][j] != INT32_MAX && dis[j] > dis[u] + grid[u][j])
			{
				dis[j] = dis[u] + grid[u][j];
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << dis[i] << " ";
	}
	cout << endl;
}

/*
6 9 
1 2 1
1 3 12
2 3 9
2 4 3
3 5 5
4 3 4
4 5 13 
4 6 15
5 6 4

*/