#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        //乘积为正/负的最长子数组
        vector<int> ndp(n, 0), pdp(n, 0);   
        
        if(nums[0] < 0){
            ndp[0] = 1;
        } else if(nums[0] >0){
            pdp[0] = 1;
        }

        int res = pdp[0];
        for(int i=1; i<n; i++){
            if(nums[i] < 0){
                ndp[i] = pdp[i-1]+1;
                if(ndp[i-1] == 0){
                    pdp[i] = 0;
                } else {
                    pdp[i] = ndp[i-1]+1;
                }
            } else if(nums[i] == 0){
                ndp[i] = 0;
                pdp[i] = 0;
            } else {
                if(ndp[i-1] == 0){
                    ndp[i] = 0;
                } else {
                    ndp[i] = ndp[i-1]+1;
                }
                pdp[i] = pdp[i-1]+1;                
            }
            res = max(res, pdp[i]);
        }
        return res;

    }
};

//优化了空间
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int n = nums.size();

        //乘积为正/负的最长子数组
        int ndp = 0, pdp=0;   
        
        if(nums[0] < 0){
            ndp = 1;
        } else if(nums[0] >0){
            pdp = 1;
        }

        int res = pdp;
        for(int i=1; i<n; i++){
            int tempNdp = ndp, tempPdp = pdp;
            if(nums[i] < 0){
                ndp = tempPdp+1;
                if(tempNdp == 0){
                    pdp = 0;
                } else {
                    pdp = tempNdp+1;
                }
            } else if(nums[i] == 0){
                ndp = 0;
                pdp = 0;
            } else {
                if(tempNdp == 0){
                    ndp = 0;
                } else {
                    ndp = tempNdp+1;
                }
                pdp = tempPdp+1;                
            }
            res = max(res, pdp);
        }
        return res;

    }
};
/*
分析: 分三种情况讨论，如果很难找到状态转移方程，可以使用列表法，列出所有的情况，然后找到规律

方法:

总结:

*/