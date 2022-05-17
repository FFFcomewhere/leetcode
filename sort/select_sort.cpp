#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int> &nums)
{
    int n = nums.size();
    int min_index = 0;
    for(int i=0; i<n-1;i++){
        min_index = i;
        for(int j=i+1; j<n; j++){
            if(nums[min_index] > nums[j]){
                min_index = j;
            }
        }
        swap(nums[i], nums[min_index]);
    }

}
11111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    select_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}