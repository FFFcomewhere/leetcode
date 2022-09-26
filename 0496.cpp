#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//暴力枚举 时间复杂度O(n^2)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //暴力枚举
        int m = nums1.size(), n = nums2.size();
        vector<int> res(m, -1);

        for(int i=0; i<m; i++){
            //是否找到x
            bool xFlag = false;
            for(int j=0; j<n; j++){
                if(nums1[i] == nums2[j]){
                    xFlag = true;
                }
                if(xFlag == true && nums2[j] > nums1[i]){
                    res[i] = nums2[j];
                    break;
                }
            }
        }
        return res;
    }
};


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //单调栈
        unordered_map<int, int> h;
        stack<int> s;

        for(int i=nums2.size()-1; i>=0; i--){
            for(;!s.empty() && nums2[i] >= s.top();){
                s.pop();
            }

            if(!s.empty()){
                h[nums2[i]] = s.top();
            } else {
                h[nums2[i]] = -1;
            }
            s.push(nums2[i]);
        }

        vector<int> res(nums1.size());
        for(int i = 0; i<nums1.size(); i++){
            res[i] = h[nums1[i]];
        }
        
        return res;
    }
};

/*
分析:

方法:

总结:

*/