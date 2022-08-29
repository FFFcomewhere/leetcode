#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  int maxArea(vector<int> &height)
  {
    int n = height.size();
    int v = 0, l = 0, r = n - 1;

    for (; l < r;)
    {

      v = max(v, (r - l) * min(height[l], height[r]));
      if (height[l] <= height[r])
      {
        l++;
      }
      else
      {
        r--;
      }
    }

    return v;
  }
};

/*
分析: 观察关系式， 找到变化的趋势， 可以看出从两侧向中间遍历， 一个乘数必定变小，那要求最大值，必须要另一个乘数变大；
                即移动较小的端点

方法: 双指针

总结:

*/
