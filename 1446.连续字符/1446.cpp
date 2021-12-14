#include <iostream>
#include <string>

using namespace std;

int maxPower(string& s)
{
    int maxPowerLength = 1, temp = 1;
    for(int i = 0; i < s.size() - 1; i++)
    {
        if(s[i] == s[i+1]) temp++;
        else{
            //maxPowerLength  = maxPowerLength>temp?maxPowerLength:temp;
            temp = 1;
        }
        maxPowerLength  = maxPowerLength>temp?maxPowerLength:temp;
    }
    return maxPowerLength;
}

int main()
{
    string s = "cc";
    int length = maxPower(s);
    cout << length << endl;
}