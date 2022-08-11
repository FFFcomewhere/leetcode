#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//二分查找
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        if (n == 0)
        {
            return -1;
        }
        if (n == 1)
        {
            if (nums[0] == target)
            {
                return 0;
            }
            else
            {
                return -1;
            }
        }

        int left = 0, right = n - 1;

        for (; left <= right;)
        {
            int mid = (right - left) / 2 + left;
            if (target == nums[mid])
            {
                return mid;
            }
            if (nums[0] <= nums[mid])
            {
                if (nums[0] <= target && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else
            {
                if (nums[mid] < target && target <= nums[n - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

/*
分析: 对于局部有序数组，二分法仍然可以找到对应值，只是需要对是否有序进行判断

方法:

总结:

*/