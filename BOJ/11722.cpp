#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1001

int a1[MAX];
int a2[MAX];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i];
	}

	int n2 = 0;
	for (int i = 1; i <= n1; i++) {
		a2[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (a1[i] < a1[j]) {
				a2[i] = max(a2[i], a2[j] + 1);
			}
		}
		n2 = max(a2[i], n2);
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}