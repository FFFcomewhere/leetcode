#include<iostream>
#include<vector>

using namespace std;

void bubble_sort(vector<int> &nums)
{
    int n = nums.size();

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n-1-i; j++){
            if(nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
            }
        }
    }    

}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    bubble_sort(nums);

    for(int i = 0; i<nums.size(); i++){
        cout<<nums[i]<<" ";
    }


}