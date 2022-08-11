#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//快排  O(nlogn) O(n^2)
class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        return nums[nums.size() - k];
    }
};


/*
分析:

方法:

总结:

*/