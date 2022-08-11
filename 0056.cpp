#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals)
  {
    int n = intervals.size();

    if (n == 0)
    {
      return {};
    }
    //先按第一个元素进行排序　把５种情况变为３种
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;

    for (auto e : intervals)
    {
      int L = e[0], R = e[1];

      //如果二者相离，则直接将元素添加进去
      if (res.size() == 0 || res.back()[1] < L)
      {
        res.push_back(e);
      }
      else
      { 
        //相交和包含的区别在于新区间的末尾是谁
        res.back()[1] = max(R, res.back()[1]);
      }
    }
    return res;
  }
};

/*
分析:  分类讨论，然后使用排序减少情况，何时入队

方法:　排序　＋　模拟

总结:　分类讨论，分析

*/