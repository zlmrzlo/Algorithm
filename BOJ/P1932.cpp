#include <iostream>
using namespace std;

int a;
int b[501][501];
int c[501][501];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> a;
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> b[i][j];
		}
	}

	return 0;
}