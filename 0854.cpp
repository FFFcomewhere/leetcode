#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
#include <queue>
using namespace std;

class Solution {
public:
    int kSimilarity(string s1, string s2) {
        int n=s1.size();
        if(n==1){
            return 0;
        }
        vector<queue<int>> errIndex(6);
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){ 
                errIndex[s2[i]-'a'].push(i);
            }
        }

        // for(int i=0; i<6; i++){
        //     for(int j=0; j<errIndex[i].size(); j++){
        //         cout<<errIndex[i].front()<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<int> dp(n, 0);
        if(s1[0] != s2[0]){
            int j = errIndex[s2[0]-'a'].front();
            errIndex[s2[0]-'a'].pop();
            int temp = s1[0];
            s1[0] = s2[j];
            s1[j] = temp;

            dp[0] = 1;
        }

        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]){
                int j = errIndex[s2[i]-'a'].front();
                errIndex[s2[i]-'a'].pop();
                int temp = s1[i];
                s1[i] = s2[j];
                s1[j] = temp;

                dp[i] = dp[i-1] + 1;
            }
        }

        return dp[n-1];
    }
};

/*
分析:

方法:

总结:

*/