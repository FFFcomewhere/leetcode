#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map> 
#include <sstream>   
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> printVertically(string s) {
        //存储单词
        stringstream ss(s);
        string word;
        vector<string> book;

        int _max = 0;
        for(;ss>>word;){
            int _size = word.size();
            _max = max(_max, _size);
            book.emplace_back(word);
        }


        cout<<_max<<endl;
        vector<string> res(_max);
        //连接单词
        //第i位
        for(int i=0; i<_max; i++){
            int _size = book.size();
            string subStr(_size, ' ');
            //第j个单词
            for(int j=0; j<_size; j++){
                if(book[j].size()-1 < i){
                    continue;
                }
                subStr[j] = book[j][i];
            }

            //对尾部空格进行判断
            int k=_size-1;
            for(; k>=0; k--){
                if(subStr[k] != ' '){
                    break;
                }
            }
            if(k!=-1){
                subStr = subStr.substr(0, k+1);
            }
            res[i]=subStr;
        }

        return res;
    }
};  

int main(){
    Solution s;
    vector<string> book = s.printVertically("CONTEST IS COMING");
    
    for(int i=0; i<book.size(); i++){
        cout<<book[i]<<endl;
    }

    return 0;
}

/*
分析:

方法:

总结:

*/