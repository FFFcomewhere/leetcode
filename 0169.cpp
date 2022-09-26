#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//使用hash 两次遍历 时间On 空间On
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> h;
        for(auto e:nums){
            h[e]++;
        }

        int res = 0;
        int _max = 0;
        for(auto e:h){
            if(_max < e.second){
                _max = e.second;
                res = e.first;
            }
        }
        return res;
    }
};

//摩尔记票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int res = 0;
        int resNum = 0;
       
        for(auto e:nums){
            if(res == e){
                resNum++;
            } else {
                if(resNum==0){
                    res = e;
                } else {
                    resNum--;
                }
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