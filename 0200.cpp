#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//DFS
class Solution
{
public:
    int next[2][4] = {
        {0, 1, 0, -1},
        {1, 0, -1, 0}};
    int numIslands(vector<vector<char>> &grid)
    {
        int sum = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != '0')
                {
                    feedBack(grid, i, j);
                    sum++;
                }
            }
        }

        return sum;
    }

    void feedBack(vector<vector<char>> &grid, int x, int y)
    {
        grid[x][y] = '0';

        for (int step = 0; step < 4; step++)
        {
            int tempX = x + next[0][step];
            int tempY = y + next[1][step];
            if (tempX >= 0 && tempX < grid.size() && tempY >= 0 && tempY < grid[0].size() && grid[tempX][tempY] != '0')
            {
                feedBack(grid, tempX, tempY);
            }
        }
        return;
    }
};

//BFS
class Solution
{
public:
    int next[2][4] = {
        {0, 1, 0, -1},
        {1, 0, -1, 0}};
    int numIslands(vector<vector<char>> &grid)
    {
        int sum = 0;

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] != '0')
                {
                    sum++;

                    queue<pair<int, int>> q;
                    q.push(pair<int, int>{i, j});

                    for (; !q.empty();)
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int step = 0; step < 4; step++)
                        {
                            int newX = x + next[0][step];
                            int newY = y + next[1][step];

                            if (newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size() && grid[newX][newY] != '0')
                            {
                                grid[newX][newY] = '0';
                                q.push(pair<int, int>{newX, newY});
                            }
                        }
                    }
                }
            }
        }
        return sum;
    }
};
/*
分析:

方法:

总结:

*/