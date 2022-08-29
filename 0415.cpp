#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1, j = num2.size()-1;
        string res = "";
        int temp = 0, carry = 0;

        for(;i>=0 || j>=0 || carry!=0;){
            int n1 = 0, n2 = 0;
            if(i>=0) {
                n1 = int(num1[i]) - int('0');
            }
            if(j>=0) {
                n2 = int(num2[j]) - int('0');
            }
            temp = n1 + n2 + carry;
            carry = temp / 10;

            res.push_back(temp%10+'0');
            i--;
            j--;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

/*
分析: 模拟加法运算

方法:

总结:

*/