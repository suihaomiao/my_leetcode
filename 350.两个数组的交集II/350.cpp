#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
{
    // unordered_map存储数字及出现的次数
    unordered_map<int, int> buckets1;
    unordered_map<int, int> buckets2;
    vector<int> res;
    for (int i = 0; i < nums1.size(); ++i)
    {
        ++buckets1[nums1[i]];
    }

    for(int i = 0; i < nums2.size(); ++i){
        ++buckets2[nums2[i]];
    }

    for(int n: nums2){
        if(buckets1.find(n) != buckets1.end()){
            //如果n能在nums1中被找到
            //需要比较，n出现次数
            //此时buckets1[n]一定是小的那个
            buckets1[n] = buckets1[n] < buckets2[n]? buckets1[n]: buckets2[n];
            while(buckets1[n]-- > 0){
                res.push_back(n);
            }
        }
    }

    return res;
}


int main(){
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};      
    vector<int> res = intersect(nums1, nums2);
    for(auto n: res)
        cout << n << " ";
    cout << endl;
}