#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//动态规划
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int _min = INT_MAX, _max = 0;
        for (auto e : prices)
        {
            _max = max(_max, e - _min);
            _min = min(_min, e);
        }

        return _max;
    }
};

/*
分析:

方法:

总结:

*/