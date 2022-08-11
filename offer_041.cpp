#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class MovingAverage
{
public:
    int data[100000];
    int left;
    int right;
    int size;
    int sum;
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        this->size = size;
        left = 0;
        right = 0;
        sum = 0;
    }

    double next(int val)
    {
        data[right] = val;
        right++;
        if (right - left > size)
        {
            sum -= data[left];
            left++;
        }

        sum += val;
        return double(sum) / (right - left);
    }
};

/*
分析: 滑动窗口

方法:

总结:

*/