#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//使用单调栈
class StockSpanner {
private:
    stack<pair<int, int>> stk;
    int idx;  
public:
    StockSpanner() {
        stk.emplace(make_pair(-1, INT_MAX));
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        stk.emplace(make_pair(idx, price));

        for(;stk.top().second<=price;){
            stk.pop();
        }

        int res = idx-stk.top().first;
        stk.emplace(idx, price);
        return res;
    }
};



/*
分析:

方法:

总结:

*/