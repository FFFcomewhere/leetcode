#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//直接模拟
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> people(num_people,0);

        //people编号 单次发放糖果数量
        int i=0, num=1;
        for(;candies>0;){
            people[i] += min(num, candies);
            candies -= min(num, candies);
            i++;
            if(i==num_people){
                i=0;
            }
            num++;
        }

        return people;
    }
};

//数学上找规律

/*
分析:

方法:

总结:

*/