#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//排序 时间 O(nklogk)  空间O(nk)
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> h;
        //排序
        for (string &str : strs)
        {
            string key = str;
            sort(key.begin(), key.end());
            h[key].emplace_back(str);
        }

        vector<vector<string>> res;
        for (auto i = h.begin(); i != h.end(); i++)
        {
            res.emplace_back(i->second);
        }
        return res;
    }
};



//计数 应为字母异构次的字母完全一样，所以出现的单词书也相等

/*
分析:   排序法： 由于字母异位词的字母完全一样，所以排序后的值也相等，可以直接排序
        计数法：  应为字母异构次的字母完全一样，所以出现的单词树也相等
方法:

总结:

*/