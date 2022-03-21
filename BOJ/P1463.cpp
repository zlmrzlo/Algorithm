#include <bits/stdc++.h>
using namespace std;

// 10 -> 9 -> 3 -> 1
// 33 -> 32 -> 16 -> 8 -> 4 -> 2 -> 1
// 33 -> 11 -> 10 -> 9 -> 3 -> 1
// 34 -> 17 -> 16 -> 8 -> 4 -> 2 -> 1
int a[1000001];
void Solution(void) {
	int n1 = 0;
	for (int i = 2; i < 1000001; i *= 2) {
		a[i] = ++n1;
	}
	int n2 = 0;
	for (int i = 3; i < 1000001; i *= 3) {
		a[i] = ++n2;
	}

	int n3;
	cin >> n3;

	int n4 = 0, n5 = 0, n6 = 0;
	while (n3 != 1) {
		if (a[n3 - 1] != 0) {
			n4 = a[n3 - 1] + 1;
		}
		if (n3 % 3 == 0) {
			n3 /= 3;
			n5++;
			continue;
		}
		if (n3 % 2 == 0) {
			n3 /= 2;
			n6++;
			continue;
		}

	}
	cout << n4;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}