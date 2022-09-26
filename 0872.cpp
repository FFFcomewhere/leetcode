#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;
//dfs+标记
class Solution {
public:
    vector<vector<int>> tag;
    unordered_map<int, int> h;
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int res=0;
        tag.resize(n, vector<int>(n, 0));

        //dfs+标记
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1 && tag[i][j]==0){
                    int tagSign = i*n+j+1;
                    h[tagSign] = dfs(grid, i, j, tagSign);
                    res = max(res, h[tagSign]);
                }
            }
        }
        //遍历标记，判断是否可以合并小岛
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int tempArea = 1;
                    unordered_set<int> s;
                    //遍历四个方向
                    for(int k=0; k<4; k++){
                        int x = i+dir[k][0];
                        int y = j+dir[k][1];
                        if(x>=0 && x<n && y>=0 && y<n && grid[x][y]==1 && s.find(tag[x][y])==s.end()){
                            tempArea += h[tag[x][y]];
                            s.insert(tag[x][y]);
                        }
                    }
                    res = max(res, tempArea);
                }
            }
        }
        return res;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, int tagSign){
        int res=1;
        
        tag[x][y] = tagSign;

        for(int step=0; step<4; step++){
            int nx = x+dir[step][0];
            int ny = y+dir[step][1];
            if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid.size() && grid[nx][ny]==1 && tag[nx][ny]==0){
                res += dfs(grid, nx, ny, tagSign);
            }
        }

        return res;
    }
};
/*
分析:

方法:

总结:

*/