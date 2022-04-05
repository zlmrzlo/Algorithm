#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 15 + 1

int a1[MAX];
int a2[MAX];
int n1;
int n4 = 0;
void Input() {
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i] >> a2[i];
	}
}

void DFS(int day, int sum, int add) {
	if (day == n1 + 1) {
		n4 = max(n4, sum);
		return;
	}
	else if (day > n1 + 1) {
		sum -= add;
		n4 = max(n4, sum);
		return;
	}

	for (int i = day; i <= n1; i++) {
		DFS(i + a1[i], sum + a2[i], a2[i]);
	}
}

void Solution(void) {
	DFS(1, 0, 0);
	cout << n4 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}