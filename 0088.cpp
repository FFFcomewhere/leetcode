#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//双指针  时间O(m+n)  空间O(m+n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> res(m+n);
        int i=0,j=0,k=0;
        for(;i<m && j<n;){
            if(nums1[i]<nums2[j]){
                res[k++] = nums1[i++];
            } else {
                res[k++] = nums2[j++];
            }
        }

        for(;i<m;){
            res[k++] = nums1[i++];
        }

        for(;j<n;){
            res[k++] = nums2[j++];
        }        

        nums1 = res; 
        return;
    }
};

//双指针 反向插入 时间O(m+n) 空间O(1)
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        for (; i >= 0 && j >= 0;)
        {
            if (nums1[i] > nums2[j])
            {
                nums1[k--] = nums1[i--];
            }
            else
            {
                nums1[k--] = nums2[j--];
            }
        }

        for (; i >= 0;)
        {
            nums1[k--] = nums1[i--];
        }

        for (; j >= 0;)
        {
            nums1[k--] = nums2[j--];
        }

        return;
    }
};
/*
分析:

方法:

总结:

*/