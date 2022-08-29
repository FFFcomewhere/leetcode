#include <iostream>
#include <vector>

using namespace std;

void heap_sort(vector<int> &nums)
{
    int n = nums.size();

    //构建大顶堆
    for(int i= ){
        //从第一个非叶子节点，从下下向上，从右向左

    }
}

void adjust(vector<int> &nums, int i, int length){
    //向下调至
    for(int k= 2*i+1; k<length; k++){
        //左节点大于右节点，交换
        if(k-1>=0 && nums[k-1] > nums[k]){
            k--;
        }

        //子节点大于父节点，交换
        if(nums[k] > nums[i]){
            swap(nums[i], nums[k]);
            i=k;
        } else {
            break;
        }
    }
}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    heap_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}