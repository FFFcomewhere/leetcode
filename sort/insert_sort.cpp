#include <iostream>
#include <vector>

using namespace std;

void insert_sort(vector<int>& nums){
    int n =nums.size();

    int prev_index, current;
    for(int i=1; i<n; i++){
        prev_index = i-1;
        current = nums[i];
        for(;prev_index >=0 && nums[prev_index] > current;){
            nums[prev_index+1] = nums[prev_index];
            prev_index--;
        }
        nums[prev_index+1] = current;
    }
}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1,100, 0, 9, 4};

    insert_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}