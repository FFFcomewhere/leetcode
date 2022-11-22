#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
#include <unordered_set>    
#include <stack>
using namespace std;

unordered_set<char> ops = {'!', '|', '&'};
unordered_set<char> flags = {'t', 'f'};
class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> s;

        for(auto e:expression){
            if(e == ')'){
                //出栈
                vector<bool> flag;
                char op=' ';
                for(;!s.empty();){
                    //find op
                    if(ops.find(s.top()) != ops.end()){
                        op = s.top();
                        s.pop();
                        break;
                    }
                    //find flag
                    if(flags.find(s.top()) != flags.end()){
                        if(s.top() == 't'){
                            flag.emplace_back(true);
                        } else {
                            flag.emplace_back(false);
                        }
                    }
                    s.pop();
                }

                bool newE = flag[0];

                //根据不同op进行操作
                for(auto f:flag){
                    if(op == '!'){
                        newE = !newE;
                        break;
                    }

                    if(op == '&'){
                        newE &= f;
                    } else {
                        newE |= f;
                    }
                }
                cout<<" new "<<newE<<" new ";
                if(newE == true){
                    s.push('t');
                } else {
                    s.push('f');
                }
            } else {
                //入栈
                s.push(e);
            }
        }
        
        return s.top() == 't';
    }
};

int main(){
    Solution s;
    string expersion = "!(f)";
    s.parseBoolExpr(expersion);

    return 0;
}

/*
分析:

方法:

总结:

*/