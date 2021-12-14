#include <iostream>
#include <string>

using namespace std;

bool judge(string s, int l, int r)
{
    int length = r - l + 1;
    if(length == 1)  return true;
    while(l < r)
    {
        if(s[l] != s[r]) return false;
        else{
            ++l;
            --r;
        }
    }
    return true;
}

bool validPalindrome(string s){
        //头尾双指针，解法
        //因为题目可以允许删除一个字符，则遇到字符不等时，可以根据下一位字符情况移动
        int size = s.size();
        int r = size -1;
        int l = 0;
        while(l < r)
        {
            if(s[l] == s[r]) 
            {
                ++l;
                --r;
            }
            else{
                return judge(s, ++l, r) || judge(s, l, --r);
            }
        }
        return false;
    }

int main()
{
    string s = "atbbga";
    cout << true << endl;
    bool res = validPalindrome(s);
    cout << res << endl;
}