#include <iostream>
#include <vector>

using namespace std;


bool search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1, mid;
        while(start <= end)
        {
            mid = (start + end)/2;
            if(nums[mid] == target) return true;
            if(nums[mid] == nums[start]){
                ++start;
                continue;
            }
            if(nums[mid] == nums[end]){
                --end;
                continue;
            }
            //在旋转后的数组，用二分法查询，有一个特点
            //即start-mid 和mid-end一定有一段是有序排列的！！！！
            if(nums[mid] > nums[start]) //即start-mid是增序排列的
                if(target > nums[start] && target <= nums[mid])    //再判断target是否落在这个区间
                    //target落在该区间，移动start
                    start = mid + 1;
                else    end = mid - 1;
            else if(nums[mid] < nums[end])//同理，如果mid小于end，则认为mid-end是增序排列的
                if(target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else end = mid - 1;
        }
        return false;
    }


    int main()
    {
        vector<int> a = {1,3,5};
        int target = 5;
        cout << true << endl;
        cout << search(a,target) << endl;
    }