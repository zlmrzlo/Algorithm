#include <iostream>
#include <cmath>
using namespace std;

#define MAX_SIZE 14
int board[MAX_SIZE];
int totalLine;
int totalCount;

void NQueens(int currentLine) {
	bool check;
	if (currentLine == totalLine) {
		totalCount++;
		return;
	}
	for (int i = 0; i < totalLine; i++) {
		check = true;
		for (int j = 0; j < currentLine; j++) {
			if (board[j] == i || abs(currentLine - j) == abs(i - board[j])) {
				check = false;
				break;
			}
		}

		if (check) {
			board[currentLine] = i;
			NQueens(currentLine + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> totalLine;
	totalCount = 0;
	NQueens(0);
	cout << totalCount << endl;

	return 0;
}