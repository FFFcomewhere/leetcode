#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

class Solution {
public:
    int reachNumber(int target) {
        int res=0, k=0;
        target = abs(target);

        for(;res<target;){
            k++;
            res += k;
        }

        if(res == target){
            return k;
        } 

        for(;(res-target)&1;){
            k++;
            res += k;
        }
        return k;
    }
};

//数学推理 时间O(target^0.5) 空间O(1)
class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int k = 0;
        for(; target > 0;){
            k++;
            target -= k;
        }

        if(target%2 == 0){
            return k;
        } else {
            return k+1+k%2;
        }
    }
};

/*
分析:

方法:

总结:

*/