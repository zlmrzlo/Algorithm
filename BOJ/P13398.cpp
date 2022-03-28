#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 100001

int a1[MAX];
int a2[MAX];
int a3[MAX];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i];
	}

	a2[1] = a1[1];
	int n2 = a2[1];
	for (int i = 2; i <= n1; i++) {
		a2[i] = max(a1[i], a2[i - 1] + a1[i]);
		n2 = max(a2[i], n2);
	}

	a3[n1] = a1[n1];
	for (int i = n1 - 1; i >= 1; i--) {
		a3[i] = max(a1[i], a3[i + 1] + a1[i]);
	}

	for (int i = 2; i <= n1; i++) {
		n2 = max(n2, a2[i - 1] + a3[i + 1]);
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}