#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

// 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

// 有效字符串需满足：

// 左括号必须用相同类型的右括号闭合。
// 左括号必须以正确的顺序闭合。

// 来源：力扣（LeetCode）
// 链接：https://leetcode-cn.com/problems/valid-parentheses
// 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

bool isValid(const string &s)
{
    cout << s<< endl;
    if(s.empty()) return true;
    stack<char> data;
    data.push('?');
    if((s[0] == ')') || (s[0] == ']') ||(s[0] == '}')) return false;
    for(int i =0; i < s.length(); i++)
    {
        if((s[i] == '(') || (s[i] == '[') || (s[i] == '{'))
        {
            data.push(s[i]);
            continue;
        } 
        if(s[i] == ')')
        {
            if(data.top() == '(')
                data.pop();
            else
            {
                return false;
            }
        }
        if(s[i] == ']')
        {
            if(data.top() == '[')
                data.pop();
            else
            {
                return false;
            }
        }
        if(s[i] == '}')
        {
            if(data.top() == '{')
                data.pop();
            else
            {
                return false;
            }
        }
    }
    if(data.size() == 1) return true;
    return false;
}

int main()
{
    string s = "]";
    cout << isValid(s) << endl;
    cout << true << endl;
    cout << false << endl;

}





