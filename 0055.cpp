#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int rightMost = 0;
        for(int i=0; i<n; i++){ 
            if(i <= rightMost){
                rightMost = max(rightMost, i+nums[i]);
                if(rightMost >= n-1){
                    return true;
                }
            }
        }

        return false;
    }
};

/*
分析: 这是一个最远目标问题，只要最远能跳到的地方超过目标点，就认为可以到达
 
方法: 贪心算法

总结: 针对这种最远和最近可到达，可以使用贪心

*/