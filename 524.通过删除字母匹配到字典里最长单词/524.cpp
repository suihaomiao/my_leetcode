#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

    string findLongestWord(string s, vector<string>& dictionary) {
        //sort(dictionary.begin(), dictionary.end());
        //cout << dictionary[2] << endl;
        int size_d,ps,pd, size_s = s.size(),count = 0;
        int max_count = 0; 
        string res = "";
        for(auto i = dictionary.begin(); i != dictionary.end(); ++i)
        {
            size_d = (*i).size();
            count = 0;
            pd = 0;

            for(ps = 0; ps < size_s; )
            {
                //cout << s[ps] << endl;
                //cout << i[pd] << endl;
                if(s[ps] == (*i)[pd])
                {
                    ++ps;
                    ++pd;
                    ++count;
                }
                else ++ps;
            }
            if(count == (*i).size() && count >= max_count)
            {
                if(count == max_count)
                {
                    for(int a = 0; a < (*i).size(); ++a)
                    {
                        if(res[a] < (*i)[a]) break;
                        if(res[a] > (*i)[a])
                        {
                            res = (*i);
                            break;
                        }
                    }
                }
                else
                {
                    res = (*i);
                    max_count = count;
                }
            } 
        }
        return res;
    }

    int main()
    {
        string s = "wordgoodgoodgoodbestword";
        vector<string> dictionary = {"word","good","best","good"};
        cout << findLongestWord(s, dictionary) << endl;
        
     }