#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        vector<int> leftMax(n, 0), rightMax(n, 0);

        //自左向右扫描
        leftMax[0] = height[0];
        for(int i=1; i<n; i++){
            leftMax[i] = max(leftMax[i-1], height[i]);
        }

        //自右向左扫描
        rightMax[n-1] = height[n-1];
        for(int i=n-2; i>=0; i--){
            rightMax[i] = max(rightMax[i+1], height[i]);
        }   

        int res = 0;
        for(int i=0; i<n; i++){
            res += min(leftMax[i], rightMax[i]) - height[i];
        }     
        return res;
    }
};

/*
分析:

方法:

总结:

*/