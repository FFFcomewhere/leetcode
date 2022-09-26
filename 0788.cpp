#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

unordered_map<char, char> RotateNum{
    {'0', '0'},
    {'1', '1'},
    {'8', '8'},
    {'2', '5'},
    {'5', '2'},
    {'6', '9'},
    {'9', '6'}
};

//暴力迭代 时间nlogn 空间 logn
class Solution {

public:
    int rotatedDigits(int n) {
        int res=0;

        for(int i=1; i<=n; i++){
            string num = to_string(i);
            bool valid = true, diff = false;
            for(auto e:num){
                if(RotateNum.find(e) == RotateNum.end()){
                    valid = false;
                } else if(RotateNum[e] != e){
                    diff = true;
                }
                
            }
            if(valid && diff){
                res++;
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