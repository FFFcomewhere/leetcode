#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isUgly(int n) {
        if(n == 0){
            return false;
        } else if(n == 1){
            return true;
        }

        for(;n != 1;){
            if(n%5 == 0){
                n /= 5;
            } else if(n%3 == 0){
                n /= 3;
            } else if(n%2 == 0){
                n /= 2;
            } else{
                return false;
            }
        }
        return true;
    }
};

/*
分析:

方法:

总结:

*/