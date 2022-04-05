#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		int n = nums.size();
		// quickSort(nums, 0, n - 1);
		// heapBuild(nums, n);
		// for (int i = 0; i < n - 1; ++i) {
		//     swap(nums[0], nums[n - i - 1]);
		//     heapfy(nums, n - i - 1, 0);
		// }

		// sort(nums.begin(), nums.end());

		// stable_sort(nums.begin(), nums.end());
		// return nums;

		vector<int> copy(nums);
		mergeSort(nums, copy, 0, n - 1);

		return copy;
	}

private:
	void mergeSort(vector<int>& nums, vector<int>& copy, int low, int high) {
		if (low >= high) {
			return;
		}

		int mid = low + (high - low) / 2;
		int left1 = low, right1 = mid, left2 = mid + 1, right2 = high;
		mergeSort(copy, nums, left1, right1);
		mergeSort(copy, nums, left2, right2);
		int index = left1;

		while (left1 <= right1 && left2 <= right2) {
			copy[index++] = nums[left1] < nums[left2] ? nums[left1++] : nums[left2++];
		}

		while (left1 <= right1) {
			copy[index++] = nums[left1++];
		}


		while (left2 <= right2) {
			copy[index++] = nums[left2++];
		}
	}

	void heapfy(vector<int>& nums, int n, int i) {
		int l = 2 * i + 1, r = 2 * i + 2, max = i;
		if (l < n && nums[l] > nums[max]) {
			max = l;
		}

		if (r < n && nums[r] > nums[max]) {
			max = r;
		}

		if (max != i) {
			swap(nums[i], nums[max]);
			heapfy(nums, n, max);
		}
	}

	void heapBuild(vector<int>& nums, int n) {
		int i = (n - 2) / 2;

		for (; i >= 0; --i) {
			heapfy(nums, n, i);
		}
	}

	void quickSort(vector<int>& nums, int left, int right) {
		if (left >= right) {
			return;
		}
		int tmp = nums[left];
		int first = left;
		int last = right;
		while (first < last) {
			while (first < last && nums[last] >= tmp) {
				--last;
			}

			if (first < last) {
				nums[first++] = nums[last];
			}

			while (first < last && nums[first] <= tmp) {
				++first;
			}

			if (first < last) {
				nums[last--] = nums[first];
			}
		}

		nums[first] = tmp;
		quickSort(nums, left, first - 1);
		quickSort(nums, first + 1, right);
	}
};

int main()
{
    std::cout << "Hello World!\n";
}

