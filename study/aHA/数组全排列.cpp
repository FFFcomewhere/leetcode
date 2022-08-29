#include <iostream>
using namespace std;

void dfs(int a[], int book[], int step, int max_step)
{
  if (step >= max_step)
  {
    for (int i = 0; i < max_step; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;

    return;
  }

  for (int i = 0; i < max_step; i++)
  {
    if (book[i] == 0)
    {
      book[i] = 1;
      a[step] = i;
      dfs(a, book, step + 1, max_step);
      book[i] = 0;
    }
  }

  return;
}

int main()
{
  int a[3] = {1, 2, 3};
  int book[3] = {0};

  dfs(a, book, 0, 3);

  return 0;
}