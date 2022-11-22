#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//前缀和遍历 但是还有些问题
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> sums(n+1, 0);
        for(int i=1; i<=n; i++){
            if(nums[i-1] >= k){
                return 1;
            }
            sums[i] = sums[i-1] + nums[i-1];
        }

        int res = INT_MAX;
        int j = 0, lastj = 0;
        for(int i=0; i<=n; i++){
            if(j==n+1){
                j=lastj+1;
            }
            for(; j<=n; j++){
                if(sums[j]-sums[i] >= k){
                    res = min(res, j-i);
                    lastj = j;
                    break;
                }
            }
        }

        if(res == INT_MAX){
            return -1;
        } else {
            return res;
        }
    }
};

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n = nums.size();
        long sums[n + 1];
        sums[0] = 0L;
        for(int i=0; i<n; i++){
            if(nums[i] >= k){
                return 1;
            }
            sums[i+1] = sums[i] + nums[i];
        }

        int res = INT_MAX;
        //使用双端队列解决问题
        deque<int> q;
        for(int i=0; i<=n; i++){
            //优化一，删除不可能的i值
            long sum = sums[i];
            for(;!q.empty() && sum - nums[q.front()] >= k;){
                res = min(res, i-q.front());
                q.pop_front();
            }

            //优化二，删除不可能的j值
            for(;!q.empty() && sums[q.back()] >= sum;){
                q.pop_back();
            }
            q.push_back(i);
        }
        

        if(res == INT_MAX){
            return -1;
        } else {
            return res;
        }
    }
};

/*
分析:

方法:

总结:

*/