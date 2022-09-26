#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//找相邻字母的规律 5倍或者10倍
class Solution {
public:
    int romanToInt(string s) {
        int n=s.size();
        unordered_map<char, int> h{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                    {'C', 100}, {'D',500}, {'M', 1000}};
        int res=0;

        for(int i=0; i<n; i++){
            res += h[s[i]];
            if(i>0 && (5*h[s[i-1]] == h[s[i]] || 10*h[s[i-1]] == h[s[i]])){
                res -= 2 * h[s[i-1]];
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