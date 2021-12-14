#include <iostream>
#include <vector>

using namespace std;

    int singleNonDuplicate(vector<int>& nums) {
        //题目要求时间复杂度为O(logn)，即必须要二分法来求解了
        int l = 0, r = nums.size() - 1, mid;
        if(r == l) return nums[0];
        while(l <= r)
        {
            mid = (l+r)/2;
            //其余数都是成对出现，仅有一个数不是成对出现，数组size必然是奇数
            //若mid及不等于mid-1也不等于mid+1，即mid就是单独出现的数
            if(l == mid && r == mid) return nums[mid];
            if(nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            if((mid+1) % 2 == 1)//mid位置是个奇数情况
            {
                if(nums[mid] == nums[mid + 1])
                    //mid和mid+1值相等，即前面全是成对出现的，单独的数出现在后面
                    l = mid + 1;
                else
                    //如果不等，则单独的数在前面
                    r = mid;
            }
            else{//如果mid位置是个偶数情况
                if(nums[mid] == nums[mid - 1])
                    //mid和mid-1值相等，即前面全是成对出现的，单独的数出现在后面
                    l = mid+1;
                else   
                    //如果不相等，则单独的数出现在前面
                    r = mid;
            }
            
        }
        return 0;
    }


int main()
{
    vector<int> a = {1,1,2,2,3,3,4,5,5,7,7};
    cout << singleNonDuplicate(a) << endl;
}