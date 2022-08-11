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
class Solution
{
public:
  int lengthOfLongestSubstring(string s)
  {
    int l = 0, r = -1;
    unordered_set<char> hm;
    int res = 0;

    for (; l < s.size(); l++)
    {

      //当l不为第一个时,删除上一次储存的字符
      if (l != 0)
      {
        hm.erase(s[l - 1]);
      }

      //右指针寻找到重复字符
      for (; r + 1 < s.size() && !hm.count(s[r + 1]);)
      {
        hm.insert(s[r + 1]);
        r++;
      }

      res = max(r - l + 1, res);
    }
    return res;
  }
};

/*
分析: 最长不重复字符串,关键点最长且不重复 ,可以使用滑动窗口或者双指针

方法: 滑动窗口 画的窗口一定要注意先对R进行判断，再对R进行操作，即使用R+1
      滑动窗口的本质，就是一个队列，当不满足条件时，左侧出队，正常情况移动右侧端点即可。
总结: 无

*/