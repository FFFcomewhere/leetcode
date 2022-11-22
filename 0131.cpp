#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;


//最普通的回溯算法
class Solution {
private:
    vector<vector<string>> res;

public:
    vector<vector<string>> partition(string s) {
        vector<string> subRes;
        feedback(s, 0, subRes);

        return res;
    }

    void feedback(string s, int index, vector<string> subRes){
        int n=s.size();
        if(index == n){
            res.push_back(subRes);
            return;
        }

        for(int i=index; i<n; i++){
            if(!checkHui(s, index, i)) {
                continue;
            }

            subRes.push_back(s.substr(index, i+1-index));
            feedback(s, i+1, subRes);
            subRes.pop_back();
        }
        return;
    }

    bool checkHui(string s, int l, int r){
        for(;l<r;){
            if(s[l] != s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }

};

//使用dp 进行优化
class Solution {
private:
    vector<vector<string>> res;

public:
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<string> subRes;
        vector<vector<bool>> dp(n, vector<bool>(n, true));

        //dp[i][j] = dp[i+1][j-1]
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }



        feedback(s, 0, subRes, dp);

        return res;
    }

    void feedback(string s, int index, vector<string> subRes,vector<vector<bool>> dp){
        int n=s.size();
        if(index == n){
            res.push_back(subRes);
            return;
        }

        for(int i=index; i<n; i++){
            if(dp[index][i]) {
            subRes.push_back(s.substr(index, i+1-index));
            feedback(s, i+1, subRes, dp);
            subRes.pop_back();
            }
        }
        return;
    }
};

/*
分析:

方法:

总结:

*/