#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//链表模拟  超时
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        list<int> l;
        for(auto e:arr){
            l.push_back(e);
        }

        int i=0;
        auto iter=l.begin();
        for(;i<k;){
            auto iter1 = iter;
            advance(iter1, 1);
            cout<<*iter<<" "<<*iter1<<" "<<i<<endl;
            if(*iter < *(iter1)){
                int data = *iter;
                l.pop_front();
                l.push_back(data);
                iter = l.begin();
                i=1;
            } else {
                int data = *iter1;
                l.erase(iter1);
                l.push_back(data);
                i++;
            }
        }

        return *iter;
    }
};

//双指针 模拟
class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int l=0, r=1;
        int i=0;
        for(;i<k;){
            if(r>=arr.size()){
                r=0;
            }
            if(arr[l] < arr[r]){
                l=r;
                r++;
                i=1;
            } else {
                r++;
                i++;
            }
        }

        return arr[l];
    }
};

/*
分析:

方法:

总结:

*/