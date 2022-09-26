#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
#include <sstream>
using namespace std;

//stringstream 库 先切割再倒叙组装
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        vector<string> words;

        for(;ss>>word;){
            words.emplace_back(word);
        }

        string res = "";
        for(int i=words.size()-1; i>=0; i--){
            res += words[i] + " ";
        }

        return res.substr(0, res.size()-1);
    }   
};

//反转整个字符串 再反转单个单词，就相当于反转单词顺序
class Solution {
public:
    string reverseWords(string s) {
        //先反转整个字符串
        reverse(s.begin(), s.end());

        //反转单个单词，并去除无效空格
        int index = 0;
        for(int start=0; start<s.size(); start++){
            if(s[start] != ' '){
                //填充一个空格,并将index移到下一个单词头部
                if(index != 0){
                    s[index++] = ' '; 
                }


                //遍历单个单词
                int end = start;
                for(;end<s.size() && s[end] != ' ';){
                    s[index++] = s[end++];
                }
                
                //反转单个单词
                reverse(s.begin()+index-(end-start), s.begin()+index);
                start = end;

            }  
        }
        s.erase(s.begin()+index, s.end());
        return s;
    }   
};
/*
分析:

方法:

总结:

*/