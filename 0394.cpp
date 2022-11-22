#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//凌乱的栈
class Solution {
public:
    string decodeString(string s) {
        stack<char> stk;
        string res;
        for(auto e:s){
            //出栈
            if(e == ']'){
                string temp;
                for(;stk.top() != '[';){
                    temp += stk.top();
                    stk.pop();
                }
                reverse(temp.begin(), temp.end());

                stk.pop();
                int num = 0;
                int i=0;
                for(;!stk.empty() && (stk.top() >= '0' && stk.top() <= '9');){
                    num = num + (stk.top()-'0')*pow(10, i);
                    stk.pop();
                    i++;
                }

                string newTmep;
                for(int i=0; i<num; i++){
                    newTmep += temp;
                }
                //cout<<newTmep<<" ";

                if(stk.empty()){
                    res += newTmep;
                } else {
                    for(auto e:newTmep){
                        stk.push(e);
                    }
                }
            } else {
                stk.push(e);
            }
        }

        //最后一段
        string temp;
        for(;!stk.empty();){
            temp += stk.top();
            stk.pop(); 
        }
        reverse(temp.begin(), temp.end());
        res += temp;

        return res;
    }
};

//精简版
class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        stack<int> mults;

        string res = "";
        int mult = 0;
        for(auto e:s){
            if(e == '[') {
                stk.push(res);
                mults.push(mult);
                mult = 0;
                res = "";
            } else if(e == ']') {
                string temp = "";
                for(int i=0; i<mults.top(); i++){
                    temp += res;
                }

                res = stk.top() + temp;
                mults.pop();
                stk.pop();
            } else if(e >= '0' && e <= '9') {
                mult = 10*mult + e-'0'; 
            } else {
                res.push_back(e);
            }
        }

        return res;
    }
};

/*
分析:

方法:

总结:

*/