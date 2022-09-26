#include <iostream>
#include <vector>
#include <list>
#include <map>
using namespace std;

class Solution
{
public:
	string longestPalindrome(string s)
	{
		int n = s.size();

		if (n < 2)
		{
			return s;
		}

		int begin = 0, _max = 1;
		vector<vector<int>> dp(n, vector<int>(n));

		//所有元素自己本身是回文子串
		for (int i = 0; i < n; i++)
		{
			dp[i][i] = 1;
		}

		//按长度进行遍历
		for (int L = 2; L <= n; L++)
		{
			for (int i = 0; i < n; i++)
			{
				int j = L + i - 1;

				//越界
				if (j >= n)
				{
					break;
				}

				if (s[i] == s[j])
				{
					//长度为2时
					if (j - i < 3)
					{
						dp[i][j] = 1;
					}
					else
					{
						dp[i][j] = dp[i + 1][j - 1];
					}
				}
				else
				{
					dp[i][j] = false;
				}

				//选择较长值
				if (dp[i][j] && _max < j - i + 1)
				{
					_max = j - i + 1;
					begin = i;
				}
			}
		}

		return s.substr(begin, _max);
	}
};

class Solution {
public:
    string longestPalindrome(string s) {
        //中心扩散
        int l = 0, r = 0, n = s.size();

        for(int i=0; i<n; i++){
            pair<int, int> p1 = extend(s, i, i);
            pair<int, int> p2 = extend(s, i, i+1);
            
            if(r-l < p1.second - p1.first){
                r = p1.second;
                l = p1.first;
            }

            if(r-l < p2.second - p2.first){
                r = p2.second;
                l = p2.first;
            }
        }
        

        return s.substr(l, r-l+1);
    }

    pair<int, int> extend(string s, int l, int r){
        for(;l>=0 && r<s.size() && s[l] == s[r];){
            l--;
            r++;
        }
        //退出判断是多+1次， 这里-1
        return {l+1, r-1};
    }
};

/*
分析:   回文子串的子串也是回文子串， 根据这个特性，可以从最短的回文子串开始扩展， 同时要注意越界条件以及最短的回文子串是1

方法: 动态规划

总结: 动规的要素就是观察一个状态是否可以转化为另一个状态

*/