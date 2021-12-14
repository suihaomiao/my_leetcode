#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int>& nums) {
        //二分法求解
        int l = 0, r = nums.size() - 1, mid;
        int mins = nums[l];
        while(l <= r)
        {
            mid = (r + l)/2;
            if(nums[mid] < mins)
                mins = nums[mid];
            if(nums[mid] == nums[l])
            {
                ++l;
                continue;
            }
            if(nums[mid] == nums[r])
            {
                --r;
                continue;
            }
            if(nums[mid] > nums[l])//表示l-mid段是增序排列的
            {
                if(nums[l] < mins)
                    mins = nums[l];
                l = mid;
            }
            else if(nums[mid] < nums[r])//表示mid-r是增序排列的
            {
                if(nums[mid] < mins)
                    mins = nums[mid];
                r = mid;
            }
        }
        return mins;
    }


int main()
{
    vector<int> a = {2,2,2,0,1};
    cout << findMin(a) << endl;
}