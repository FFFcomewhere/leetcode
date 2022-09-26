#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        
        int _max = INT_MIN;
        for(auto e:nums){
            _max = max(_max, e);
        }

        vector<int> data(_max+1, 0);
        for(auto e:nums){
            data[e] += e;
        }

        return rob(data);
    }

    int rob(vector<int> &data){
        int n = data.size();
        if(n==1){
            return data[0];
        }

        int dp0 = data[0], dp1 = max(data[0], data[1]);

        for(int i=2; i<n; i++){
            int temp = dp1;
            dp1 = max(dp0+data[i], dp1);
            dp0 = temp;
        }
        return dp1;
    }
};

/*
分析: 挖掘题目隐含条件，相邻元素不能选取，转化为打家劫舍问题

方法:

总结:

*/