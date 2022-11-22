#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//简单模拟题
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> h;

        for(auto e:cpdomains){
            //find num
            int i=0, n=e.size(), num=0;
            for(;i<n && e[i] != ' ';){
                i++;
            }

            num = atoi(e.substr(0, i).c_str());

            //倒叙 遍历域名
            i=n-1;
            for(;i>=0;i--){
                if(e[i] == '.' || e[i] == ' '){
                    h[e.substr(i+1, n-i)]+=num;
                }
            }
        }

        vector<string> res(h.size());
        int i=0;
        for(auto e:h){
            //cout<<e.first<<" "<<e.second<<endl;
            res[i] = to_string(e.second)+ " " + e.first;
            i++;
        }

        return res;
    }
};

/*
分析:

方法:

总结:

*/