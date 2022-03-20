#include <iostream>
#include <vector>
using namespace std;

#define MAX_LINE 9
int board[MAX_LINE][MAX_LINE];
vector<pair<int, int>> zero;
int zeroCount;
int found = false;

bool SudokuCheck(pair<int, int> zeroPoint) {
	for (int i = 0; i < MAX_LINE; i++) {
		if (board[zeroPoint.first][i] == board[zeroPoint.first][zeroPoint.second] && i != zeroPoint.second) {
			return false;
		}
		if (board[i][zeroPoint.second] == board[zeroPoint.first][zeroPoint.second] && i != zeroPoint.first) {
			return false;
		}
	}

	int boxRow = zeroPoint.first / 3;
	int boxCol = zeroPoint.second / 3;
	for (int i = 3 * boxRow; i < 3 * boxRow + 3; i++) {
		for (int j = 3 * boxCol; j < 3 * boxCol + 3; j++) {
			if (board[i][j] == board[zeroPoint.first][zeroPoint.second]) {
				if (i != zeroPoint.first && j != zeroPoint.second) {
					return false;
				}
			}
		}
	}

	return true;
}

void Sudoku(int currentCount) {
	if (currentCount == zeroCount) {
		// 3. 스도쿠 출력
		for (int i = 0; i < MAX_LINE; i++) {
			for (int j = 0; j < MAX_LINE; j++) {
				cout << board[i][j] << ' ';
			}
			cout << '\n';
		}
		found = true;
		return;
	}

	for (int i = 1; i <= MAX_LINE; i++) {
		board[zero[currentCount].first][zero[currentCount].second] = i;
		if (SudokuCheck(zero[currentCount])) {
			Sudoku(currentCount + 1);
		}
		if (found) {
			return;
		}
	}
	board[zero[currentCount].first][zero[currentCount].second] = 0;
	return;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	
	// 1. 스도쿠 입력
	zeroCount = 0;
	for (int i = 0; i < MAX_LINE; i++) {
		for (int j = 0; j < MAX_LINE; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				zeroCount++;
				zero.push_back({ i,j });
			}
		}
	}

	// 2. 스도쿠 도출
	Sudoku(0);


	return 0;
}

// 참고 : https://cryptosalamander.tistory.com/59