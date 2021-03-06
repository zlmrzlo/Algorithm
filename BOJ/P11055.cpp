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
		a2[i] = a1[i];
		for (int j = 1; j < i; j++) {
			if (a1[i] > a1[j] && a2[i] < a2[j] + a1[i]) {
				a2[i] = a2[j] + a1[i];
			}
		}
		n2 = max(n2, a2[i]);
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// ????: https://yabmoons.tistory.com/87