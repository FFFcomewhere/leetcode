#include <iostream>
#include <vector>

using namespace std;
/*
本质： 选定一个基准，将小于基准到放在左边，大于基准的放在右边，再交换基准和最小值的位置；
        再对

方法：分治
*/
void quick_sort(vector<int>& nums, int l, int r)
{
    int i = l, j = r;
    int index = l;
    if(i<j){
        for(;i<j;){
            for(;i<j && nums[i] < nums[index];){
                i++;
            }

            for (; i<j && nums[j] > nums[index];)
            {
                j--;
            }

            swap(nums[i], nums[j]);
        }

        swap(nums[index], nums[j]);
        quick_sort(nums, l, j);
        quick_sort(nums, j + 1, r);
    }
    return ;
}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    quick_sort(nums, 0, nums.size()-1);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}