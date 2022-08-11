#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//二分
class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {

    int n = numbers.size();
    int l = 0, r = n - 1;

    for (int i = 0; i < n; i++)
    {

      l = i + 1;
      r = n - 1;

      for (; l <= r;)
      {
        int mid = (l + r) / 2;
        if (numbers[mid] + numbers[i] == target)
        {
          return {i + 1, mid + 1};
        }
        else if (numbers[mid] + numbers[i] > target)
        {
          r = mid - 1;
        }
        else
        {
          l = mid + 1;
        }
      }
    }

    return {0, 0};
  }
};

//双指针
class Solution
{
public:
  vector<int> twoSum(vector<int> &numbers, int target)
  {

    int n = numbers.size(), l = 0, r = n - 1;

    for (; l < r;)
    {
      if (numbers[l] + numbers[r] == target)
      {
        return {l + 1, r + 1};
      }
      else if (numbers[l] + numbers[r] < target)
      {
        l++;
      }
      else
      {
        r--;
      }
    }

    return {0, 0};
  }
};

/*
分析: 数组已排好序，可以直接上二分；
            左右各设置一个指针，如果和小于目标值，l++，和大于目标值，r--

方法:　二分查找; 双指针

总结:　已排序数组　直接二分；双指针

*/