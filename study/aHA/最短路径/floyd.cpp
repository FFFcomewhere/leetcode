#include <iostream>

using namespace std;

int grid[10][10];
int n, m;

int main()
{
	n = 4;
	m = 8;

	//初始矩阵
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
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

	cout << "input over" << endl;

	//核心代码 即每两个点, 通过添加其他中间点缩短路径
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (grid[i][k] != INT32_MAX && grid[k][j] != INT32_MAX && grid[i][j] > grid[i][k] + grid[k][j])
				{
					grid[i][j] = grid[i][k] + grid[k][j];
				}
			}
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

/*
1 2 2
1 3 6
1 4 4
2 3  3
3 1 7
3 4 1
4 1 5
4 3 12
*/