#include <iostream>
#include <vector>
using namespace std;

int answer[21][21][21];

int Func1(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}

	if (a > 20 || b > 20 || c > 20) {
		a = 20, b = 20, c = 20;
	}

	if (answer[a][b][c] == 0) {
		if (a < b && b < c) {
			answer[a][b][c] = Func1(a, b, c - 1) + Func1(a, b - 1, c - 1) - Func1(a, b - 1, c);
		}
		else {
			answer[a][b][c] = Func1(a - 1, b, c) + Func1(a - 1, b - 1, c) +
				Func1(a - 1, b, c - 1) - Func1(a - 1, b - 1, c - 1);
		}
	}
	return answer[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= 20; j++) {
			for (int k = 1; k <= 20; k++) {
				Func1(i, j, k);
			}
		}
	}

	int a, b, c;
	while (true) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << Func1(a, b, c) << '\n';
	}
	return 0;
}