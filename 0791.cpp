#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
#include <unordered_set>    
using namespace std;

//未优化版本
class Solution {
public:
    string customSortString(string order, string s) {
        unordered_set<char> src;
        unordered_map<char, int> unite; //<字符,数量>

        for(auto e:order){
            src.insert(e);
        }

        for(auto e:s){
            if(src.find(e) != src.end()){
                unite[e]++;
            }
        }

        string res="";

        //从左集合提取元素
        for(auto e:order){
            if(unite.find(e) != unite.end()){
                res += string(e, unite[e]);
            }
        }

        //在尾部加入右集合元素
        for(auto e:s){
            if(unite.find(e) == unite.end()){
                res += e;
            }
        }
        
        return res;
    }
};


//简化流程
class Solution {
public:
    string customSortString(string order, string s) {
        //从s中统计字符出现次数
        vector<int> nums(26);
        
        for(int i=0; i<s.size(); i++){
            nums[s[i]-'a']++;
        }

        //遍历order，清空hash,构建新res
        string res="";
        for(auto e:order){
            if(nums[e-'a'] > 0){
                res += string(nums[e-'a'], e);
                nums[e-'a'] = 0;
            }
        }

        //根据剩余Hash,在尾部添加剩余元素
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != 0){
                res += string(nums[i], i+'a'); 
            }
        }
        return res;
    }
};

//直接使用赋权重， 排序
class Solution {
public:
    string customSortString(string order, string s) {
        //对每个字符赋权重
        vector<int> val(26);
        for(int i=0; i<order.size(); i++){
            val[order[i]-'a'] = i+1;
        }

        sort(s.begin(), s.end(), [&](char a, char b) {
            return val[a-'a'] < val[b-'a'];
        });
        return s;
    }
};
/*
分析:

方法:

总结:

*/