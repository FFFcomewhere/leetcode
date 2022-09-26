#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;

//hash
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> h;
        for(int i=0; i<n; i++){
            h[nums[i]]++;
        }

        vector<pair<int, int>> hVec(h.size());
        int i=0;
        for(auto e:h){
            hVec[i] = make_pair(e.first, e.second);
            i++;
        }

        vector<int> res(n);
        i=0;
        sort(hVec.begin(), hVec.end(), [](pair<int, int> a, pair<int, int> b) {
            if(a.second > b.second || (a.second == b.second && a.first < b.first)){
                return false;
            } else {
                return true;
            }
        });

        i=0;
        for(auto e:hVec){
            for(int j=0; j<e.second; j++, i++){
                res[i] = e.first;
            }
        }

        return res;
    }
};

//
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int, int> h;
        for(int i=0; i<n; i++){
            h[nums[i]]++;
        }

        sort(nums.begin(), nums.end(), [&](const int a, const int b) {
            if(h[a] != h[b]){
                return h[a]<h[b];
            } 
            return a>b;
        });
    
        return nums;
    }
};

/*
分析:

方法:

总结:

*/