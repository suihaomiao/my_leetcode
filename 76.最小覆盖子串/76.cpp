#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string minWindow(string s, string t){
    //一旦涉及到子串，子序列基本都用到滑动窗口
    //这个应该算是滑动窗口比较难得题目了
    //边界处理
    if(t.size() > s.size())
        return "";
    //两个指针
    int l = 0, r =0;
    //最小子串的l和r位置
    int min_l, min_r,ans = INT32_MAX;
    int needcnt = t.size();
    //bucket存放的是一共需要的各字符数量
    unordered_map<char, int> buckets;
    //flags存放的是，t的字符在26个字母中是否包含
    vector<bool> flags(256,false);
    //window存放的是，子串的字符和字符数量,初始化均为-1表示没有任何元素
    vector<int> window(256);
    for(int i = 0; i < needcnt; ++i){
        ++buckets[t[i]];
        if(flags[t[i]] == false){
            flags[t[i]] = true;
        }
    }
    
    while(r < s.size()){
        //首先增加r，直到包含了所有的字符
        if(flags[s[r]] == true){
            if(buckets[s[r]] > 0){
                --buckets[s[r]];
                --needcnt;
                continue;
            }
            //cout << "123" << endl;
            //如果字符s[r]多了或者needcnt==0，都可以开始移动l
            while(buckets[s[r]] <= 0 && needcnt == 0){
                if(flags[s[l]] != true){
                    ++l;
                }
                else{//如果该字符是需要的
                    if(buckets[s[l]] < 0){//该字符的需要字符小于0,意味着有多该字符
                        ++l;
                        continue;
                    }
                    else{//反之，该字符不能删除，记录下此时的状态，
                        if(ans < (r - l +1)){
                            ans = r - l + 1;
                            min_l = l;
                            min_r = r;
                        }
                    }
                }
            }
        }
        ++r;
    }

    return s.substr(min_l, min_r);    
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout << minWindow(s, t) << endl;

}