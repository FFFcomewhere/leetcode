#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        for(;l<=r;){
            int m = (r-l)/2 + l;
            if(nums[m] == target){
                return m;
            }
            //在右侧
            if(nums[m] < target){
                if(nums[m] < target && target <= nums[r]){
                    l = m+1;
                } else {
                    r = m-1;
                }
            } else {
                if(nums[l] <= target && target < nums[m]){
                    r = m-1;
                } else {
                    l = m+1;
                }
            }

        }
        return -1;
    }
};


int main(){
    Solution s;
    vector<int> nums{4,5,6,7,0,1,2};
    int target = 0;

    cout<<s.search(nums, target);
    return 0;
}
/*
分析:

方法:

总结:

*/