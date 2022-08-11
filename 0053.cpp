#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//动态规划
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int f0 = 0, _max = nums[0];

        for (int i = 0; i < nums.size(); i++)
        {
            f0 = max(nums[i], f0 + nums[i]);
            _max = max(_max, f0);
        }
        return _max;
    }
};

//贪心算法
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int res = INT_MIN;
        int n = nums.size();
        int sum = 0;
    
        for(int i =0 ;i <n; i++){
            sum += nums[i];
            res = max(res, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        return res;
    }
};

//分治
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        return findMaxSubArray(nums, 0, nums.size() - 1);
    }

    int findMaxSubArray(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }
        int mid = (right - left) / 2 + left;

        //可能的结果为左区间， 右区间， 跨区间
        int leftSum = findMaxSubArray(nums, left, mid);
        int rightSum = findMaxSubArray(nums, mid + 1, right);
        int midSum = getMidSum(nums, left, mid, right);

        int res = max(leftSum, rightSum);
        res = max(res, mid);
        return res;
    }

    int getMidSum(vector<int> &nums, int left, int mid, int right)
    {
        int leftSum = INT_MIN;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            leftSum = max(sum, leftSum);
        }

        int rightSum = INT_MIN;
        sum = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            rightSum = max(sum, rightSum);
        }

        return leftSum + right;
    }
};

/*
分析:

方法:

总结:

*/