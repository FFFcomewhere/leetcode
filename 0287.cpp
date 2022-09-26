#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
using namespace std;



class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;

        for(;;){
            if(slow==fast && slow!=0 && fast!=0){
                break;
            }
            slow = nums[slow];
            fast = nums[nums[fast]];
        }

        slow=0;
        for(;slow!=fast;){
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return nums[slow];
    }
};

/*
分析:

方法:

总结:

*/