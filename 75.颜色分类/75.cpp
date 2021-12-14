#include <iostream>
#include <vector>

using namespace std;

void sortColors(vector<int> &nums)
{
    //使用双指针，达到遍历一次
    int l = 0, r = nums.size() - 1;
    int i = 0;
    while (i <= nums.size()/2)
    {
        if (nums[i] == 0)
        {
            swap(nums[i], nums[l]);
            ++i;++l;
            continue;
        }
        if (nums[i] == 2)
        {
            swap(nums[i], nums[r]);
            ++i;--r;
            continue;
        }
        if(nums[i] == 1){
            ++i;
        }
    }
}

int main()
{
    vector<int> nums = {2,0};
    sortColors(nums);
    //cout << nums << endl;
    for(auto i:nums)
        cout << i << " ";
    cout << endl;
}