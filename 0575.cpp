#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_set>    
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        //hash
        int n=candyType.size();
        int res=0;
        unordered_set<int> h;
        for(auto e:candyType){
            if(h.find(e) == h.end()){
                h.insert(e);
                res++;    
            } 
        }
        return min(res, n/2);
    }
};

class Solution {
public:
    int distributeCandies(vector<int> &candyType) {
        return min(unordered_set<int>(candyType.begin(), candyType.end()).size(), candyType.size() / 2);
    }
};


/*
分析:

方法:

总结:

*/