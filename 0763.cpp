
#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        int h[26];
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            h[s[i] - 'a'] = i;
        }

        vector<int> res;
        int start = 0, end = 0;
        for (int i = 0; i < n; i++)
        {
            end = max(end, h[s[i] - 'a']);
            if (i == end)
            {
                res.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return res;
    }
};

/*
分析:   记录每个字母出现的最后一次位置，从左开始遍历字符串，对比end和last[s[i]-'a'],如果end<last[s[i]-'a']，
        则end=last[s[i]-'a']，否则end不变，记录end-start+1，start=end+1


方法:  贪心算法

总结:   

*/

