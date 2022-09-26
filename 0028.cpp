#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//暴力枚举 时间O(n*m) 空间O(1)
class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(), n = needle.size();
        if(m < n){
            return -1;
        }

        for(int i=0; i<=m-n; i++){
            int j=i, k=0;
            
            for(;j<m && haystack[j] == needle[k]; ){
                j++;
                k++;
            }
            if(k==n){
                return i;
            }
        }
        return -1;
    }
};
/*
分析:

方法:

总结:

*/