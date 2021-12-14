#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> findAnagrams(const string& s, const string& p)
{
        //滑动窗口
        //固定长度的滑动窗口，只需要维护在窗口内的字符要求即可。
        //即每次l和r一起动，每次移除l++的字符和++r的字符
        //注意越界就行
        int size_s = s.size();
        int size_p = p.size();
        if(size_s < size_p)
            return {};
        int r = size_p - 1, l = 0;

        vector<int> count_s(26);
        vector<int> count_p(26);
        vector<int> ans;
    
        for(int i = 0; i < size_p; ++i){
            ++count_s[s[i] - 'a'];//这里需要把p窗口内的s字符一起统计
            ++count_p[p[i] - 'a'];
        }

        while(1){
            if(count_s == count_p)
                ans.push_back(l);

            if(r == size_s - 1)
                break;

            --count_s[s[l++] - 'a'];
            ++count_s[s[++r] - 'a'];
        }

        return ans;
}

int main(){
    string s = "cbaebabacd";
    string p = "abc";
    vector<int> res = findAnagrams(s, p);
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;

}
