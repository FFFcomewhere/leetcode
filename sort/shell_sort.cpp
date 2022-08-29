#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int> &nums)
{
    int n = nums.size();
    int k = 1;
    for(;k<n/3;){
        k*=3;
    }

    for(;k>=1;){
        int prev_index, current;
        for(int i=1; i<n; i++){
            prev_index = i-k;
            current = nums[i];
            for(;prev_index >=0 && nums[prev_index] > current;){
                nums[prev_index+k] = nums[prev_index];
                prev_index-=k;
            }

            nums[prev_index+k] = current;
        }
        k/=3;
    }


}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4, -2, 900};

    shell_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}