#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

//提前计数
class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        int l = 0, r = 0;
        for (auto &e : s)
        {
            if (e == ')')
            {
                r++;
            }
        }

        string res = "";
        for (auto &e : s)
        {
            if (e == '(')
            {
                if (r > 0)
                {
                    res += e;
                    l++;
                    r--;
                }
                else
                {
                    ;
                }
            }
            else if (e == ')')
            {
                if (l > 0)
                {
                    res += e;
                    l--;
                }
                else
                {
                    r--;
                }
            }
            else
            {
                res += e;
            }
        }

        return res;
    }
};


//栈


/*
分析:

方法:

总结:

*/