#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        
        int dpThrow = 0, dpGet = 0;
        dpThrow = 0;
        dpGet = -prices[0];

        for(int i=1; i<n; i++){
            int tempThrow = dpThrow, tempGet = dpGet;
            dpThrow = max(tempThrow, tempGet+prices[i]-fee);
            dpGet = max(tempThrow-prices[i], tempGet);
        }
        return dpThrow;
    }
};

/*
分析:

方法:

总结:

*/