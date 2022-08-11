#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> myStack;
        int n = s.size();
        if (n % 2 == 1)
        {
            return false;
        }

        for (int i = 0; i < n; i++)
        {
            if (!myStack.empty() &&
                (myStack.top() == '(' && s[i] == ')' || myStack.top() == '[' && s[i] == ']' || myStack.top() == '{' && s[i] == '}'))
            {
                myStack.pop();
            }
            else
            {
                myStack.push(s[i]);
            }
        }

        return myStack.empty();
    }
};
/*
分析: 使用栈解决

方法:

总结:

*/