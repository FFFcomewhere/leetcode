#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//双指针
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    unordered_map<int, int> h;
    int n = s.size();

    int l = 0, r = 0, _max = 0;

    for (; r < n; r++)
    {
      if (h.count(s[r]))
      {
        //包含重复字符
        _max = max(_max, r - l);
        l = max(l, h[s[r]] + 1);
        h.erase(s[r]);
      }

      h[s[r]] = r;
    }
    _max = max(_max, r - l);

    return _max;
  }
};

//滑动窗口

/*
分析: 最长不重复字符串,关键点最长且不重复 ,可以使用滑动窗口或者双指针

方法: 滑动窗口

总结: 无

*/