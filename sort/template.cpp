#include <iostream>
#include <vector>

using namespace std;

void bubble_sort(vector<int> &nums)
{
    int n = nums.size();

}

int main()
{
    vector<int> nums{300, -1, 200, -2, 1, 100, 0, 9, 4};

    bubble_sort(nums);

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}