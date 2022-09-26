#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//使用hash 处理每种情况
class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string>> h{
            {1000, "M"},
            {900,  "CM"},
            {500,  "D"},
            {400,  "CD"},
            {100,  "C"},
            {90,   "XC"},
            {50,   "L"},
            {40,   "XL"},
            {10,   "X"},
            {9,    "IX"},
            {5,    "V"},
            {4,    "IV"},
            {1,    "I"},
        };
    

        string res="";
        for(auto e:h){
            for(;num>=e.first;){
                res += e.second;
                num -=e.first;
            }
            if(num==0){
                break;
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