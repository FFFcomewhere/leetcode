#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int res = 1e7;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int j=i+1, k=n-1;
            for(; j<k;){
               int sum = nums[i] + nums[j] + nums[k];
                // 如果和为 target 直接返回答案
                if (sum == target) {
                    return target;
                }
                //更新值
                if (abs(sum - target) < abs(res - target)) {
                    res = sum;
                }

                if (sum > target) {
                    // 如果和大于 target，移动 c 对应的指针
                    int k0 = k - 1;
                    // 移动到下一个不相等的元素
                    while (j < k0 && nums[k0] == nums[k]) {
                        --k0;
                    }
                    k = k0;
                } else {
                    // 如果和小于 target，移动 b 对应的指针
                    int j0 = j + 1;
                    // 移动到下一个不相等的元素
                    while (j0 < k && nums[j0] == nums[j]) {
                        ++j0;
                    }
                    j = j0;
                }
            }
        }
        return res;
    }
};

/*
分析:

方法:

总结:

*/