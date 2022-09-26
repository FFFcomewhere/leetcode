#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//找到规律 排序 时间nlogn 空间n
class Solution {
public:
    string convert(string s, int numRows) {
        int l=s.size();
        if(numRows==1){
            return s;
        }
        vector<pair<pair<int, int>, char>> gird(l);

        int row=0, colum=0;
        bool down = true;
        for(int i=0; i<l; i++){
            gird[i] = {{row, colum}, s[i]};            
            
            if(row==numRows-1){
                down = false;
            } else if(row==0){
                down = true;
            }

            if(down){
                row++;
            } else {
                row--;
                colum++;
            }
        }

        sort(gird.begin(), gird.end());

        string res;
        for(auto e:gird){
            res.push_back(e.second);
        }

        return res;
    }
};

//找规律似乎不行诶
class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.size();
        
        string res="";
        for(int row = 0; row<numRows;row++){
            int k=row;
            for(;;){
                cout<<k<<" ";
                res.push_back(s[k]);

                //两个位置取较小
                if((k+(numRows-row-1)*2 < l && (numRows-row-1)*2 > 0) || (k+(2*numRows-2) < l && (2*numRows-2) > 0)){
                    cout<<k<<" "<<(numRows-row-1)*2<<" "<<(2*numRows-2)<<endl;
                    
                    if((numRows-row-1)*2 == 0){
                        k = k+(2*numRows-2);
                    } else if(2*numRows-2 == 0){
                        k = k+(numRows-row-1)*2;
                    } else {
                        k = min(k+(numRows-row-1)*2, k+(2*numRows-2));
                    }
                    continue;
                } else {
                    break;
                }
            }
        }

        return res;
    }
};


//存储在数组里
class Solution {
public:
    string convert(string s, int numRows) {
        int l = s.size();
        if(numRows == 1){
            return s;
        }
        vector<string> grid(numRows, "");
        int row=0;
        bool down=true;
        for(int i=0; i<l; i++){
            //cout<<s[i];
            //cout<<row<<" ";
            grid[row].push_back(s[i]);

            if(row==numRows-1){
                down = false;
            } else if(row==0){
                down = true;
            }

            if(down){
                row++;
            } else {
                row--;
            }
        }

        string res="";
        for(auto e:grid){
            res += e;
        }

        return res;
    }
};/*
分析:

方法:

总结:

*/