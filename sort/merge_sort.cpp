#include <iostream>
#include <vector>

using namespace std;

vector<int> merge(vector<int> l_nums, vector<int> r_nums);

vector<int> merge_sort(vector<int> nums)
{
    int n = nums.size();
    if(n <= 1){
        return nums;
    }
    int mid = n/2;
    vector<int> l_nums(nums.begin(), nums.begin() + mid);
    vector<int> r_nums(nums.begin() + mid, nums.end());

    return merge(merge_sort(l_nums), merge_sort(r_nums));
}

vector<int> merge(vector<int> l_nums, vector<int> r_nums)
{
    int l_size = l_nums.size(), r_size = r_nums.size();
    vector<int> res(l_size + r_size); 
    int i=0, j = 0, k = 0;
    for(;i<l_size && j<r_size;){
        if(l_nums[i] < r_nums[j]){
            res[k++] = l_nums[i++];
        } else {
            res[k++] = r_nums[j++];
        }
    }

    for(;i<l_size;){
        res[k++] = l_nums[i++];
    }

    for (; j < r_size;)
    {
        res[k++] = r_nums[j++];
    }

    return res;
}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    vector<int> res =  merge_sort(nums);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << " ";
    }
}