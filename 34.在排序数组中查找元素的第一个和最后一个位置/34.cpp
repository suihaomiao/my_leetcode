#include <iostream>
#include <vector>

using namespace std;


vector<int> searchRange(vector<int>& nums, int target)
{
        //双指针，直接遍历方法
        //时间复杂度为O(n)
        if(nums.empty()) return{-1,-1};
        int l = 0,size = nums.size(), r = size - 1;
        //如果左边没找到目标值，进入循环
        while(nums[l] != target && l < size)
        {
            ++l;
        }
        while(nums[r] != target && r > 0)
        {
            --r;
        }
        if(l == size) return {-1,-1};
        return {l,r};
}


int main()
{
    vector<int> a = {5,7,7,8,8,10};
    vector<int> res = searchRange(a, 8);
    cout << res[0] << endl;
    cout << res[1] << endl;
}