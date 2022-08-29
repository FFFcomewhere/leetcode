class Solution
{
public:
  void sortColors(vector<int> &nums)
  {
    int colors[3] = {0, 0, 0};

    for (int e : nums)
    {
      if (e == 0)
      {
        colors[0]++;
      }
      else if (e == 1)
      {
        colors[1]++;
      }
      else
      {
        colors[2]++;
      }
    }

    for (int i = 0; i < nums.size(); i++)
    {
      if (i < colors[0])
      {
        nums[i] = 0;
      }
      else if (i < colors[0] + colors[1])
      {
        nums[i] = 1;
      }
      else
      {
        nums[i] = 2;
      }
    }
    return;
  }
};

/*
分析: 题目的核心不是排序，而是统计各颜色数量

方法:　遍历

总结:　看清题意

*/