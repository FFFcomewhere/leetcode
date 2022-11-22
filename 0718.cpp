#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;


class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size(); 
        int res=0;

        for(int i=0; i<m; i++){
            if(m-i<=res){
                break;
            }
            for(int j=0; j<n; j++){
                if(n-j<=res){
                    break;
                }
                if(nums1[i] == nums2[j]){
                    int tempRes = 0;
                    for(int k=0; i+k<m && j+k<n; k++){
                        if(nums1[i+k] != nums2[j+k]){
                            break;
                        }
                        tempRes++;
                    }
                    res = max(res, tempRes);
                }
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