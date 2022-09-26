#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

vector<vector<int>> dir{
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0},
    {1, 1},
    {1, -1},
    {-1, -1},
    {-1, 1},
};

//模拟 时间复杂度 O(mn) 空间O(mn)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> res(board);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tempSum=0;
                for(int k=0; k<dir.size(); k++){
                    int newI = i + dir[k][0];
                    int newJ = j + dir[k][1];

                    if(newI>=0 && newI<m && newJ>=0 && newJ<n && board[newI][newJ] == 1){
                        tempSum++;
                    }
                }

                if(board[i][j] == 1 && (tempSum<2 || tempSum>3)){
                    res[i][j]=0;
                } else if(board[i][j] == 0 && tempSum==3){
                    res[i][j]=1;
                }
            }
        }
        board = res;
        return ;
    }
};

//模拟 添加状态 刚死 刚活 时间复杂度 O(mn) 空间O(1)
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
        //0 死 1 活 2 刚死==原来活  3刚活==原来死
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tempSum=0;
                for(int k=0; k<dir.size(); k++){
                    int newI = i + dir[k][0];
                    int newJ = j + dir[k][1];

                    if(newI>=0 && newI<m && newJ>=0 && newJ<n && (board[newI][newJ] == 1 || board[newI][newJ] == 2)){
                        tempSum++;
                    }
                }

                if((board[i][j] == 1 || board[i][j] == 2) && (tempSum<2 || tempSum>3)){
                    //刚死
                    board[i][j]=2;
                } else if((board[i][j] == 0 || board[i][j] == 3) && tempSum==3){
                    //刚活
                    board[i][j]=3;
                }
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 2){
                    board[i][j] = 0;
                } else if(board[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }

        return ;
    }
};


/*
分析:

方法:

总结:

*/