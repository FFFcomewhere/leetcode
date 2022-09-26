#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1, 0);
        dp[1] = 1;
        int p1 = 1, p2 = 1, p3 = 1;

        for(int i=2; i<=n; i++){
            int num1 = dp[p1]*2, num2 = dp[p2]*3, num3 = dp[p3]*5;
            dp[i] = min(num1, min(num2, num3));

            if(dp[i] == num1){
                p1++;
            }
            if(dp[i] == num2){
                p2++;
            }
            if(dp[i] == num3){
                p3++;
            }
        }
        return dp[n];
    }
};

/*
分析:

方法:

总结:

*/