#include <iostream>
#include <vector>

using namespace std;

//题⽬：给定一张图片，0表示无色，1表示有色，返回有色区域的个数

class Solution1 {//待优化
public:
	int areaNumInPicture(vector<vector<int>>& v) {
		if (v.empty()) {
			return -1;
		}
		int n = v.size();
		int m = v[0].size();
		vector<vector<int>> count(n, vector<int>(m));

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (1 == count[i][j]) {
					continue;
				}
				num++;
				dfs(i, j, v, count);
			}
		}

		return num;
	}

	void dfs(int x, int y, vector<vector<int>>& v, vector<vector<int>>& count) {
		if (x < 0 || x >= n || y < 0 || y >= n) {
			return;
		}

		if (1 == count[x][y]) {
			return;
		}
		count[x][y] = 1;
		if (0 == v[x][y]) {
			return;
		}
		else {
			dfs(x + 1, y, v, count);
			dfs(x, y + 1, v, count);
			dfs(x - 1, y, v, count);
			dfs(x, y - 1, v, count);
		}
	}

	int num { 0 };
	int n;
	int m;
};
int main()
{
    std::cout << "Hello World!\n";
}


