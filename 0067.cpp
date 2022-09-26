#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>   
#include <algorthm> 
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m=a.size(), n=b.size();

        int digtal=0;
        string res;
        for(int i=m-1, j=n-1; i>=0 || j>=0 || digtal==1; i--, j--){
            int add1=0, add2=0;
            if(i>=0){
                add1 = a[i]-'0';
            } 

            if(j>=0){
                add2 = b[j]-'0';
            }
            
            int tempSum = add1+add2+digtal;
            res.push_back((tempSum%2)+'0');
            digtal =  tempSum/2;
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