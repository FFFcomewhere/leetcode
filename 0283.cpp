#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  void moveZeroes(vector<int> &nums)
  {
    int n = nums.size(), l = 0, r = 0;

    for (; r < n;)
    {
      if (nums[r])
      {
        swap(nums[l], nums[r]);
        l++;
      }
      r++;
    }

    return;
  }
};

/*
分析: 　关注题目条件，原地，对于数组来说，一般使用双指针，
                将数组切割为两段，一段为已完成，一段为未完成．

方法:　双指针

总结:　数组　原地　可以使用双指针，注意遍历条件

*/