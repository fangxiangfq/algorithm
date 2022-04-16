#include <vector>
#include <algorithm>
#include <iostream>

// n, vector<uint32_t> a;
// m
// samples:
// n = 3, (3, 6, 7),  m = 5, ans = 3
// n = 3, (3, 6, 18), m = 2, ans = 9

using namespace std;

bool work(int target, int m, int n, std::vector<uint32_t>& a) {
	int count = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] >= target) {
			count += a[i] / target;
		}
		else {
			break;
		}
	}

	return count >= m;
}

uint32_t Solve(const std::vector<uint32_t>& a, uint32_t n, uint32_t m) {
	if (a.empty()) {
		return 0;
	}
	std::vector<uint32_t> tmp(a);
	sort(tmp.begin(), tmp.end(), greater<uint32_t>());
	int l = 0;
	int r = tmp[0];

	while (l <= r) {
		int mid = l + (r - l) / 2;
		if (work(mid, m, n, tmp)) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	return r;
}

int main()
{
	cout << Solve({ 3, 6, 7 }, 3, 5) << endl;
}

