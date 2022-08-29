#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    vector<string> permutation(string s)
    {
        vector<string> res;
        string sub_res;
        vector<int> used(s.size(), 0);
        sort(s.begin(), s.end());
        feed_back(res, sub_res, s, used, 0);

        return res;
    }

    void feed_back(vector<string> &res, string &sub_res, string s, vector<int> used, int start)
    {

        if (start == s.size())
        {
            res.push_back(sub_res);
            return;
        }

        for (int i = 0; i < s.size(); i++)
        {
            if (used[i] == 1)
            {
                continue;
            }

            if (i > 0 && s[i] == s[i - 1] && used[i - 1] == 1)
            {
                continue;
            }

            sub_res.push_back(s[i]);
            used[i] = 1;
            feed_back(res, sub_res, s, used, start + 1);
            used[i] = 0;
            sub_res.pop_back();
        }
    }
};

/*
分析: 参考38

方法:

总结:

*/