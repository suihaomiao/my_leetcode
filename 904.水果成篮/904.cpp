#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int totalFruit(vector<int> &fruits)
{
    //滑动窗口，在这个窗口里面仅能包含两个数
    //尽可能让窗口大
    int size = fruits.size();
    if (size == 1)
        return 1;
    if (size == 2)
        return 2;
    int l = 0, r;
    int ans = 0;
    unordered_map<int, int> buckets;
    for(r = 0; r < size; ++r){
        ++buckets[fruits[r]];
        if(buckets.size() > 2){
            --buckets[fruits[r]];
            break;
        }
    }
    ans = max(ans, r);
    if(ans == size) return ans;
    for (; r < size;)
    {
        //说明首次添加不一样的元素,移动r
        if (++buckets[fruits[r]] == 1)
        {
            //一直把l往右移动，如果有某个元素的个数为0，即找到当前满足条件的子序列
            while (buckets[fruits[l]] > 0)
            {
                if(--buckets[fruits[l++]] == 0){
                    //ans = max(ans, r - l + 1);
                    break;
                }       
            }
        }
        ans = max(ans, r - l + 1);
        ++r;
    }
    return ans;
}

int main(){
    vector<int> fruits = {0,1,0,2};
    cout << totalFruit(fruits) << endl;
}
