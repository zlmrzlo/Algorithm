#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
int a1[10][10];
bool a2[10];
void Input() {
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < n1; j++) {
			cin >> a1[i][j];
		}
	}
}

int n2 = 4e6 + 1;
void DFS(int count, int sum, int place, int next) {
	if (count == n1 && place == next) {
		n2 = min(n2, sum);
		return;
	}

	for (int i = 0; i < n1; i++) {
		if (!a2[i] && a1[next][i]) {
			a2[i] = true;
			sum += a1[next][i];
			if (sum < n2) {
				DFS(count + 1, sum, place, i);
			}
			a2[i] = false;
			sum -= a1[next][i];
		}
	}
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		DFS(0, 0, i, i);
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}