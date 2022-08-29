#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
  string reverseWords(string s)
  {
    s = s + " ";
    int n = s.size();
    int low = 0, fast = 1;

    for (; fast < n; fast++)
    {

      if (s[fast] == ' ')
      {
        for (int i = low; i < (low + fast) / 2; i++)
        {
          char temp = s[i];
          s[i] = s[fast - 1 - i + low];
          s[fast - 1 - i + low] = temp;
        }
      }
      if (s[fast - 1] == ' ' && s[fast] != ' ')
      {
        low = fast;
      }
    }
    s.assign(s.begin(), s.end() - 1);
    return s;
  }
};

/*
分析: 反转字符串,而且是间隔的单词,果断使用双指针

方法: 双指针

总结: 翻转字符串 ,直接双指针

*/