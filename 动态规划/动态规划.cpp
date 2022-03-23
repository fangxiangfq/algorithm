#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//题⽬：给你 k 种⾯值的硬币，⾯值分别为 c1, c2 ... ck ，每种硬
//币的数量⽆限，再给⼀个总⾦额 amount ，问你最少需要⼏枚硬币凑出这个
//⾦额，如果不可能凑出，算法返回 - 1 。

class Solution {
public:
	int coinChange(const vector<int>& coins, int amount)
	{
		if (0 == amount) {
			return 0;
		}
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;

		for (int i = 1; i < amount + 1; ++i) {
			for (const int& c : coins) {
				if (i < c) {
					continue;
				}
				else {
					dp[i] = min(dp[i], 1 + dp[i - c]);
				}
			}
		}

		return dp[amount] == amount + 1 ? -1 : dp[amount];
	}
};

int main()
{
	Solution s;
	cout << s.coinChange({1, 2, 3, 4}, 10) << endl;
}

