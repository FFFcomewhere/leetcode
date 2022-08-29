#include <iostream>
#include <math.h>
using namespace std;

void dfs(int nums[], int book[], int step)
{
  if (step == 9)
  {
    int a = nums[0] * 100 + nums[1] * 10 + nums[2];
    int b = nums[3] * 100 + nums[4] * 10 + nums[5];
    int c = nums[6] * 100 + nums[7] * 10 + nums[8];

    if (a + b == c)
    {
      cout << a << " " << b << " " << c << endl;
    }
    return;
  }

  for (int i = 0; i < 9; i++)
  {
    if (book[i] == 0)
    {
      book[i] = 1;
      nums[step] = i;
      dfs(nums, book, step + 1);
      book[i] = 0;
    }
  }
}

int main()
{
  cout << "i am start" << endl;
  int nums[9] = {0};
  int book[9] = {0};

  dfs(nums, book, 0);

  return 0;
}