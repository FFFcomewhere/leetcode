#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, false));
        if(s1.size()+s2.size() != s3.size()){
            return false;
        }
        dp[0][0]=true;

        for(int i=0; i<=s1.size(); i++){
            for(int j=0; j<=s2.size(); j++){
                if(i > 0){
                    dp[i][j] |= dp[i-1][j] && (s1[i-1]==s3[i+j-1]);
                }
                if(j > 0){
                    dp[i][j] |= dp[i][j-1] && (s2[j-1]==s3[i+j-1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }

};

/*
分析:

方法:

总结:

*/