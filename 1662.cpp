#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//时间On 空间On
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string str1="", str2="";
        for(auto e:word1){
            str1 += e;
        }

        for(auto e:word2){
            str2 += e;
        }

        return str1 == str2;
    }
};

//时间On 空间O1
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n1=word1.size(), n2=word2.size();
        //根据长度比较
        int sum1=0, sum2=0;
        for(auto e:word1){
            sum1+=e.size();
        }
        for(auto e:word2){
            sum2+=e.size();
        }

        if(sum1 != sum2){
            return false;
        }

        //每个字符串遍历
        int index1 = 0, index2 = 0;
        for(int i=0, j=0; i<word1.size() && j<word2.size();){
            if(word1[i][index1] != word2[j][index2]){
                return false;
            }
            
            index1++;
            index2++;

            if(index1 == word1[i].size()){
                i++;
                index1=0;
            }

            if(index2 == word2[j].size()){
                j++;
                index2=0;
            }
        }

        return true;
    }
};


/*
分析:

方法:

总结:

*/