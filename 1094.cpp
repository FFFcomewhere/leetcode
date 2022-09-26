#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>    
using namespace std;

//把每个点的人数都记录下来
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        //差分
        vector<int> nums(1001, 0);
        for(auto e:trips){
            nums[e[1]] += e[0];
            nums[e[2]] -= e[0];
        }

        for(int i=0; i<nums.size(); i++){
            //cout<<nums[i]<<" ";
            capacity -= nums[i];
            if(capacity<0){
                return false;
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