#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 51

int height, width;
int A[MAX][MAX];
int B[MAX][MAX];

void Input() {
	cin >> height >> width;

	string line;
	for (int i = 0; i < height; i++) {
		cin >> line;
		for (int j = 0; j < width; j++) {
			A[i][j] = line[j] - '0';
		}
	}

	for (int i = 0; i < height; i++) {
		cin >> line;
		for (int j = 0; j < width; j++) {
			B[i][j] = line[j] - '0';
		}
	}

	int count = 0;
	for (int i = 0; i < height - 2; i++) {
		for (int j = 0; j < width - 2; j++) {
			if (A[i][j] != B[i][j]) {
				for (int m = i; m < i + 3; m++) {
					for (int n = j; n < j + 3; n++) {
						if (A[m][n] == 0) {
							A[m][n] = 1;
						}
						else if (A[m][n] == 1) {
							A[m][n] = 0;
						}
					}
				}
				count++;
			}
		}
	}
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (A[i][j] != B[i][j]) {
				cout << -1 << endl;
				return;
			}
		}
	}
	cout << count << endl;
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}