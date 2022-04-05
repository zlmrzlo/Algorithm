#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
char a1[11][11];
vector<int> v3;
void Input() {
	cin >> n1;
	v3.resize(n1);
	for (int i = 0; i < n1; i++) {
		for (int j = i; j < n1; j++) {
			cin >> a1[i][j];
		}
	}
}

bool Sum(int count) {
	int sum = 0;
	for (int i = count; i >= 0; i--) {
		sum += v3[i];
		if (a1[i][count] == '+' && sum <= 0) {
			return false;
		}
		if (a1[i][count] == '-' && sum >= 0) {
			return false;
		}
		if (a1[i][count] == '0' && sum != 0) {
			return false;
		}
	}
	return true;
}

void DFS(int count) {
	if (count == n1) {
		for (int i = 0; i < n1; i++) {
			cout << v3[i] << ' ';
		}
		cout << endl;
		exit(0);
	}

	for (int i = -10; i <= 10; i++) {
		v3[count] = i;
		if (Sum(count)) {
			DFS(count + 1);
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