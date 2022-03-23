#include <iostream>
#include <vector>

using namespace std;

static void printSudoku(vector<vector<char>>& board) {
	for (const auto& i : board) {
		for (const auto& j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
	cout << endl;
}

class Solution {
public:
	void solveSudoku(vector<vector<char>>& board) {
		backtrack(board, 0, 0);
	}

	bool backtrack(vector<vector<char>>& board, int row, int col) {
		
		if (n == col) {
			return backtrack(board, row + 1, 0);
		}

		if (m == row) {
			return true;
		}

		if (board[row][col] != '.') {
			return backtrack(board, row, col + 1);
		}

		for (char c = '1'; c <= '9'; ++c) {
			if (!isValid(board, row, col, c)) {
				continue;
			}
			board[row][col] = c;
			if (backtrack(board, row, col + 1)) {
				return true;
			}
			board[row][col] = '.';
		}

		return false;
	}

private:

	bool isValid(vector<vector<char>>& board, int row, int col, char c) {
		for (int i = 0; i < 9; ++i) {
			if (board[i][col] == c) {
				return false;
			}
			else if (board[row][i] == c) {
				return false;
			}
			else if (board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == c) {
				return false;
			}
		}

		return true;
	}
	static const int m = 9;
	static const int n = 9;
};

int main()
{
	Solution s;
	vector<vector<char>> v = { 
		{'5','3','.','.','7','.','.','.','.'},
		{'6','.','.','1','9','5','.','.','.'},
		{'.','9','8','.','.','.','.','6','.'},
		{'8','.','.','.','6','.','.','.','3'},
		{'4','.','.','8','.','3','.','.','1'},
		{'7','.','.','.','2','.','.','.','6'},
		{'.','6','.','.','.','.','2','8','.'},
		{'.','.','.','4','1','9','.','.','5'},
		{'.','.','.','.','8','.','.','7','9'} 
	};
	s.solveSudoku(v);
	printSudoku(v);
}

