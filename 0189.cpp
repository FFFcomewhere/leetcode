#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <deque>
using namespace std;

//找规律
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    vector<int> res(n);

    for (int i = 0; i < n; i++)
    {
      res[(i + k) % n] = nums[i];
    }

    nums.assign(res.begin(), res.end());
  }
};

//使用队列
class Solution
{
public:
  void rotate(vector<int> &nums, int k)
  {
    int n = nums.size();

    deque<int> q(nums.begin(), nums.end());

    for (auto e : q)
    {
      cout << e << " ";
    }

    k = k % n;
    for (int i = 0; i < k; i++)
    {
      int data = q.front();
      q.pop_front();
      q.push_back(data);
    }

    nums.assign(q.begin(), q.end());
  }
};

/*
分析:　找到规律，可以直接使用数组　或者　使用队列

方法:　队列

总结:　无

*/