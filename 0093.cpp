#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;


//回溯
class Solution {
public:
    vector<string> res;
    vector<int> subRes;

    vector<string> restoreIpAddresses(string s) {
        subRes.resize(4);
        feedBack(s, 0, 0);
        return res;
    }

    void feedBack(string s, int index, int segId){
        //获得四段id且遍历所有字符
        if(segId == 4){
            if(index == s.size()){
                string subResStr;
                for(int i=0; i<segId; i++){
                    subResStr += to_string(subRes[i]) + ".";                    
                }
                res.emplace_back(subResStr.substr(0, subResStr.size()-1));
            }
            return ;
        }

        //没有找到四段id
        if(index == s.size()){
            return;
        }

        //筛除前导零
        if(s[index] == '0'){
            subRes[segId] =0;
            feedBack(s, index+1, segId+1);
        }

        //遍历每一个字段
        int temp = 0;
        for(int i=index; i<s.size(); i++){
            temp = temp*10 + s[i] - '0';
            if(temp > 0 && temp <= 255){
                subRes[segId] = temp;
                feedBack(s, i+1, segId+1);
            } else {
                break;
            }
        }

        return ;
    }
};

/*
分析:

方法:

总结:

*/