#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res = "";

        for(int i=0; i<command.size(); ){
            if(command[i] == 'G'){
                res += "G";
            } else {
                i++;
                if(command[i] == ')'){
                    res += "o";
                } else {
                    res += "al";
                    i += 2;
                }
            }
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