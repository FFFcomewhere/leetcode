#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//模拟加队列
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            q.emplace(i);
        }

        for (; q.size() > 1;)
        {
            for (int i = 1; i < k; i++)
            {
                q.emplace(q.front());
                q.pop();
            }
            q.pop();
        }

        return q.front();
    }
};

//约瑟夫环
class Solution
{
public:
    int findTheWinner(int n, int k)
    {
        if (n <= 1)
        {
            return n;
        }

        int ans = (findTheWinner(n - 1, k) + k) % n;
        if (ans == 0)
        {
            return n;
        }
        else
        {
            return ans;
        }
    }
};

/*
分析:   模拟加队列： 一次将队首元素放在队尾，遍历一轮后移去队首元素。

        约瑟夫环：
方法:   

总结:

*/