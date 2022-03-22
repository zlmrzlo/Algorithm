#include <bits/stdc++.h>
using namespace std;

int a[1000001];
void Solution(void) {
	int n1;
	cin >> n1;
	a[1] = 0;
	for (int i = 2; i <= n1; i++) {
		a[i] = a[i - 1] + 1;
		if (i % 3 == 0) {
			a[i] = min(a[i], a[i / 3] + 1);
		}
		if (i % 2 == 0) {
			a[i] = min(a[i], a[i / 2] + 1);
		}
	}
	cout << a[n1] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}