#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//冒泡排序  
//核心：比较相邻元素大小，将将大的元素后推
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        int flag = false;
        for (int i = 0; i < n; i++)
        {

            flag = false;
            for (int j = 0; j < n - i; j++)
            {
                if (j < n - 1 && nums[j] > nums[j + 1])
                {
                    swap(nums[j], nums[j + 1]);
                    flag = true;
                }
            }
            if (flag == false)
            {
                break;
            }
        }

        return nums;
    }
};


//选择排序
//核心：在剩余元素中选取最小值，移动的合适位置
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        int n = nums.size();

        int _min = INT_MIN;
        int _min_index = 0;
        for (int i = 0; i < n - 1; i++)
        {
            _min = nums[i];
            _min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (_min > nums[j])
                {
                    _min = nums[j];
                    _min_index = j;
                }
            }
            swap(nums[i], nums[_min_index]);
        }

        return nums;
    }
};

//快速排序
class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int l, int r)
    {
        if (l > r)
        {
            return;
        }

        int left = l, right = r;
        int index = rand() % (right - left + 1) + left;
        int temp = nums[index];

        for (; left < right;)
        {
            for (; left < right && nums[right] >= temp;)
            {
                right--;
            }
            nums[left] = nums[right];

            for (; left < right && nums[left] <= temp;)
            {
                left++;
            }
            nums[right] = nums[left];
        }

        nums[left] = temp;
        quickSort(nums, l, left - 1);
        quickSort(nums, right + 1, r);
    }
};

/*
分析:

方法:

总结:

*/