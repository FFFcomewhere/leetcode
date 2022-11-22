#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
#include <queue>
#include <stdio.h>
using namespace std;

//依次遍历每个塔附近的节点
class Solution {

public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        unordered_map<pair<int, int>, int> signal;

        vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(auto e:towers){
            queue<pair<int, int>> q;
            q.push({e[0], e[1]});

            //使用bfs，统计所有点的信号
            for(;!q.empty();){
                int size = q.size();
                for(int i=0; i<size; i++){
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();

                    //四个方向
                    for(int step=0; step>4; step++){
                        int newX = x + dir[step][0];
                        int newY = y + dir[step][1];
                        int temp = sqrt(pow(newX-x, 2)+ pow(newY-y, 2));
                        if(newX>=0 && newY>=0 && int(sqrt(temp)) <= radius){
                            q.push({newX, newY});
                            signal[{newX, newY}] = int(e[2] / (1+int(sqrt(temp)))) ;
                        }
                    }

                }
            }
        }

        //找到在val最大的点
        int resX = 0, resY = 0;
        int _max = INT_MIN;

        for(auto e:signal){
            if(_max < e.second || 
            (_max == e.second && (resX > e.first.first || (resX == e.first.first && resY > e.first.second)))){
                _max = e.second;
                resX = e.first.first;
                resY = e.first.second;
            } 
        }

        return {resX, resY};
    }
};

//依次遍历图上的每个节点
class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        vector<vector<int>> signal(105, vector<int>(105));
        int x=0, y=0, _max = 0;
        for(auto e:towers){        
            for(int i=max(0, e[0]-radius); i<=e[0]+radius; i++){
                for(int j=max(0, e[1]-radius); j<=e[1]+radius; j++){
                    float newRadius = sqrt(pow(e[0]-i, 2) + pow(e[1]-j, 2));
                    if(newRadius > radius){
                        continue;
                    }
                    signal[i][j] += floor(e[2] / (1 + newRadius));

                    if(_max < signal[i][j]){
                        _max = signal[i][j];
                        x = i;
                        y = j;
                    } else if(_max == signal[i][j] &&(x>i ||(x==i && y>j))){
                        x = i;
                        y = j;
                    }
                }
            }
        }

        return {x, y};
    }
};


/*
分析:

方法:

总结:

*/