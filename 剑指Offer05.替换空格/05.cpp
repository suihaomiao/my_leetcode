#include <iostream>
#include <string>

using namespace std;

string replaceSpace(string s)
{
    int count = 0;
    int size = s.size();
    for (int i = 0; i < size; ++i)
    {
        if (s[i] == ' ')
            ++count;
    }
    //先扩容，其中" " 和“%20”相差两个字符，因此扩大count * 2
    s.resize(size + count * 2);
    int new_size = s.size();
    //用双指针来遍历字符串
    int i = size - 1, j = new_size - 1;
    while (i >= 0 && j >= 0)
    {
        //只要不是空格，就把字符放到最后去
        if (s[i] != ' ')
            s[j--] = s[i--];
        else
        {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
            //这里i指向空格，需要再往前移动一格
            --i;
        }
    }
    return s;
}

int main()
{
    string s = "We are happy.";
    cout << replaceSpace(s) << endl;
}
