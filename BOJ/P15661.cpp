#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 20 + 1

int n1;
int n2 = 20 * 20 * 100;
int a1[MAX][MAX];
bool a2[MAX];
void Input() {
	cin >> n1;
	for (int i = 1; i <= n1; i++) {
		for (int j = 1; j <= n1; j++) {
			cin >> a1[i][j];
		}
	}
}

void DFS(int count, int next, int target) {
	if (count == target) {
		int start = 0;
		int link = 0;
		int diff;
		for (int i = 1; i <= n1; i++) {
			for (int j = 1; j <= n1; j++) {
				if (a2[i] && a2[j]) {
					start += a1[i][j];
				}
				if (!a2[i] && !a2[j]) {
					link += a1[i][j];
				}
			}
		}

		diff = abs(start - link);
		n2 = min(n2, diff);
		return;
	}

	for (int i = next; i <= n1; i++) {
		a2[i] = true;
		DFS(count + 1, i + 1, target);
		a2[i] = false;
	}
}

void Solution(void) {
	for (int i = 2; i <= n1 - 2; i++) {
		DFS(0, 1, i);
	}
	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}