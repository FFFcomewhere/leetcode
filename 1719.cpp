#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_set>    
using namespace std;

//hash 时间0n 空间on
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n=nums.size()+2;
        unordered_set<int> s;
        for(int i=1; i<=n; i++){
            s.insert(i);
        }


        for(auto e:nums){
            if(s.find(e) != s.end()){
                s.erase(e);
            }
        }

        int a=0,b=0, i=0;
        for(auto e:s){
            if(i==0){
                a = e;
                i++;
            } else {
                b = e;
                break;
            }
        }

        return {a, b};
    }
};

//数学 获得两数之和后，减去小于中值的数
class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int n=nums.size()+2;
        int cur = n*(1+n)/2;
        
        for(auto e:nums){
            cur -= e;
        }

        int sum=cur, t=cur/2;
        cur = t*(t+1)/2;

        for(auto e:nums){
            if(e<=t){
                cur -= e;
            }
        }
        return {cur, sum-cur};
    }
};

/*
分析:

方法:

总结:

*/