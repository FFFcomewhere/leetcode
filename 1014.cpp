#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        //使用滑动窗口 本质上是左侧列表寻找左侧列表最大值，左侧最大值--
        int _max = values[0]; //左侧列表最大值
        int _maxIndex = 0;
        int res = 0;
        for(int i=1; i<values.size(); i++){
            _max--;
            res = max(res, _max+values[i]);

            //最大值 被替换
            if(_max <= values[i]){
                _max = values[i];
                _maxIndex = i;
            }
        }

        return res;
    }
};
/*
分析:

方法:

总结:

*/