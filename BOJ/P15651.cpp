#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1, n2;
int a1[9];
void Input() {
	cin >> n1 >> n2;
}

void DFS(int count) {
	if (count == n2) {
		for (int i = 0; i < n2; i++) {
			cout << a1[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n1; i++) {
		a1[count] = i;
		DFS(count + 1);
	}
}

void Solution(void) {
	DFS(0);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}