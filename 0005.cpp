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

/*
分析:   回文子串的子串也是回文子串， 根据这个特性，可以从最短的回文子串开始扩展， 同时要注意越界条件以及最短的回文子串是1

方法: 动态规划

总结: 动规的要素就是观察一个状态是否可以转化为另一个状态

*/