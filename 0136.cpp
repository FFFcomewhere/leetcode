#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//法一： hash存储数字和次数，二次遍历
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> h;
        for(auto e:nums){
            h[e]++;
        }

        for(auto i:h){
            if(i.second == 1){
                return i.first;
            }
        }

        return -1;
    }
};

//法二： 使用异或运算，去除重复元素
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(auto e : nums) {
            res ^= e;
        }
        return res;
    }
};

/*
分析:

方法:

总结:

*/