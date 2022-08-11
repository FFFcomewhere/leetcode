#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//递归  空间O(mn)
class Solution {
public:
    int next[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};
    vector<int> res;
    vector<vector<int>> used;
    int m, n;

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        res.resize(m*n);
        used = matrix;
        
        for(int i=0; i<m; i++){
            used[i].assign(n, 0);
        }

        feedBack(matrix, 0, 0, 0, 0);
        
        return res;
    }

    void feedBack(vector<vector<int>> &matrix, int now, int x, int y, int direct){
        if(now == n*m){
            return;
        }

        used[x][y] = 1;
        res[now] = matrix[x][y];

        //对于一个点，最多选择四次方向,且如果选择了一个方向后，就break
        for(int i=0; i<4; i++){
            if(direct>=4){
                direct -= 4;
            }

            int now_x = x+next[0][direct];
            int now_y = y+next[1][direct];
            if(now_x>=0 && now_x<m && now_y>=0 && now_y<n && used[now_x][now_y] == 0) {
                feedBack(matrix, now+1, now_x, now_y, direct);
            break;
            }
            direct++;
        }
        
        return;
    }
};


//按层模拟 空间O(1)
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        if (m == 0 || n == 0)
        {
            return {};
        }
        vector<int> res(m * n);
        int left = 0, right = n - 1, top = 0, bottom = m - 1;
        int now = 0;
        for (; left <= right && top <= bottom;)
        {
            //上边界
            for (int i = left; i <= right; i++)
            {
                res[now++] = matrix[top][i];
            }
            //右边界
            for (int i = top + 1; i <= bottom; i++)
            {
                res[now++] = matrix[i][right];
            }
            if (left < right && top < bottom)
            {
                //下边界
                for (int i = right - 1; i >= left; i--)
                {
                    res[now++] = matrix[bottom][i];
                }
                //左边界
                for (int i = bottom - 1; i >= top + 1; i--)
                {
                    res[now++] = matrix[i][left];
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return res;
    }
};

/*
分析: 深搜

方法:

总结:

*/