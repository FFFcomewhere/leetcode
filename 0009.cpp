
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//转字符串 遍历一半 时间O(2*longn)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        } else {
            string str = to_string(x);
            int n = str.size();
            for(int i=0; i<n/2; i++){
                if(str[i] != str[n-1-i]){
                    return false;
                }
            }
        }
        return true;
    }
};

//不转字符串 直接比
class Solution {
public:
    bool isPalindrome(int x) {
        //小于0 或最后以一位是0但x不为0
        if(x < 0 || (x % 10 == 0 && x!=0)){
            return false;
        }

        int tempX = 0;
        for(;tempX<x;){
            tempX = tempX*10+x%10;
            x /= 10;
        }
        return x==tempX || x==tempX/10;
    }
};

/*
分析:

方法:

总结:

*/