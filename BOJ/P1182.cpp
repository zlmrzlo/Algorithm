#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 20

int n1, n2;
int a1[MAX];
void Input() {
	cin >> n1 >> n2;
	for (int i = 0; i < n1; i++) {
		cin >> a1[i];
	}
}

int c1;
void Solution(void) {
	for (int i = 1; i < (1 << n1); i++) {
		int n3 = 0;
		for (int k = 0; k < n1; k++) {
			if (i & (1 << k)) {
				n3 += a1[k];
			}
		}

		if (n3 == n2) {
			c1++;
		}
	}

	cout << c1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}