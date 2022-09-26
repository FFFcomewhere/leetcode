#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        string res="";
        int i=num1.size()-1, j=num2.size()-1, _add = 0;
        for(;i>=0 || j>=0 || _add != 0;){
            int x=0, y=0;
            if(i>=0){
                x = num1[i] - '0';
            }
            if(j>=0){
                y = num2[j] - '0';
            }
            int subRes = x + y + _add;
            res.push_back('0'+subRes%10);
            _add = subRes/10;
            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

/*
分析:

方法:

总结:

*/