#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
using namespace std;

class Solution
{
public:
  int eraseOverlapIntervals(vector<vector<int>> &intervals)
  {
    int n = intervals.size();

    if (n == 1)
    {
      return 0;
    }

    sort(intervals.begin(), intervals.end(), [](const auto &u, const auto &v)
         { return u[0] < v[0]; });

    vector<int> f(n, 1);

    for (int i = 1; i < n; i++)
    {
      for (int j = 0; j < i; j++)
      {
        if (intervals[j][1] <= intervals[i][0])
        {
          f[i] = max(f[i], f[j] + 1);
        }
      }
    }

    return n - *max_element(f.begin(), f.end());
  }
};

/*
分析:

方法:

总结:

*/