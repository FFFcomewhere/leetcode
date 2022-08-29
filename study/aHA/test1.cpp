#include <iostream>

using namespace std;

void change(int a[])
{
  a[1] = 100;
  cout << "change " << a[1] << endl;
}

int main()
{

  // int a[2] = {1, 2};
  // cout << "src " << a[1] << endl;
  // change(a);
  // cout << "res " << a[1] << endl;

  int a = 1;
  cin >> a;
  cout << a;

  return 0;
}