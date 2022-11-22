#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//简单模拟题 时间On 空间O(m+n)
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.size(), n = word2.size();
        int _max = max(m, n), _min = min(m, n);
        int i=0;
        string res = "";

        for(;i<_max;i++){
            if(i<m){
                res += word1[i];
            }
            if(i<n){
                res += word2[i];
            }

            if(i>=m && i<n){
                res += word2.substr(m+1, n-m);
                break;
            } else if(i>=n && i<m) {
                res += word1.substr(n+1, m-n);
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