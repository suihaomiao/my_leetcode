#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    //此类题用到的是滑动最小窗口
    if(s.size() == 0)  return 0;

    unordered_set<char> lookup;
    int max_size = 0;
    int left = 0;
        for(int i = 0; i < s.size(); i++)
        {
            //如果字符重复
            while(lookup.find(s[i]) != lookup.end())
            {
                //删除最左边的字符，直到没有重复
                lookup.erase(s[left]);
                left++;
            }
            max_size = max_size < (i - left + 1)? (i - left + 1):max_size;
            lookup.insert(s[i]);
        }
    return max_size;
}

int main()
{
    string s = "pwwkew";
    int max_size = lengthOfLongestSubstring(s);
    cout << max_size << endl;
    cout << s << endl;
}