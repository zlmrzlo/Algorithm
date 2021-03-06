#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1, n2;
int a1[9];
bool a2[9];
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

	for (int i = 0; i < n1; i++) {
		if (!a2[i]) {
			a2[i] = true;
			a1[count] = i + 1;
			DFS(count + 1);
			a2[i] = false;
		}
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