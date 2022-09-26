#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> h;

        for(auto e:nums){
            h[e]=1;
        }

        int res = 0;
        for(auto e:nums){
            //找链子
            if(h.find(e) != h.end() && h[e]!=0){
                for(int i=e-1; h.find(i) != h.end() && h[i] != 0; i--){
                    h[e] += h[i];
                    h[i] = 0;
                }
                res = max(res, h[e]);
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