#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//做加法
class Solution {
public:
    string multiply(string num1, string num2) {
        string res="";

        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        //获取num2每一位乘以num1的值
        for(int i=num2.size()-1; i>=0; i--){
            string subRes = "";
            int carry = 0;

            for(int j=num1.size()-1; j>=0 || carry!=0; j--){
                int sum=carry;
                if(j>=0){
                    sum+=(num2[i]-'0') * (num1[j]-'0');
                }
                carry = sum/10;
                subRes.push_back('0'+sum%10);
            }
            reverse(subRes.begin(), subRes.end());

            string digtal(num2.size()-1-i, '0');
            subRes += digtal;
            res = addStrings(res, subRes);
        }

        return res;

    }

    string addStrings(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        string res="";
        int carry=0;

        for(int i=m-1, j=n-1; i>=0||j>=0||carry!=0; i--,j--){
            int sum=carry;
            if(i>=0){
                sum+=num1[i]-'0';
            }
            if(j>=0){
                sum+=num2[j]-'0';
            }
            carry = sum/10;

            res.push_back('0'+sum%10) ;
        }

        reverse(res.begin(), res.end());
        return res;
    }
};


//做乘法 将值临时储存在数组中，减少对字符串的操作
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0"){
            return "0";
        }

        int m = num1.size(), n = num2.size();
        vector<int> arr(m+n, 0);
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int temp = arr[i+j+1] + (num2[i]-'0') * (num1[j]-'0');
                arr[i+j+1] = temp%10;
                arr[i+j] += temp/10;
            }
        }

        string res;

        for(int i=0; i<m+n; i++){
            if(i==0 && arr[i] == 0){
                continue;
            }
            res.push_back(arr[i]+'0');
        }

        return res;
    }
};

/*
分析:

方法:

总结:

*/