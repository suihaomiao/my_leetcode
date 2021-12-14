#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string frequencySort(string s)
{
    //桶排序的变形
    //统计各字符在字符串s中出现的频次
    unordered_map<char, int> counts;
    int max_count = 0;
    for (auto num : s){
        max_count = max(max_count, ++counts[num]);
    }
        

    //定义一个桶，桶的各个元素表示出现i次的字符
    vector<vector<char>> buckets(max_count + 1);
    for (auto p : counts){
        buckets[p.second].push_back(p.first);
    }
        
    //最后按照正序输出字符即可
    string ans;
    //从1开始，因为0是没有插入数据的
    for (int i = max_count; i > 0; --i)
    {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            for (int k = 0; k < i; ++k)
            {
                //cout << buckets[i][j] << " ";
                ans.push_back(buckets[i][j]);
            }
        }
    }
    //cout << endl;
    return ans;
}

int main()
{

    string s = "tree";
    cout << frequencySort(s) << endl;
}