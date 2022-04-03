#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1, n2;
vector<int> v1;
vector<bool> v2;
vector<int> v3;
void Input() {
	cin >> n1 >> n2;
	v1.resize(n1);
	v2.resize(n1);
	v3.resize(n1);
	for (int i = 0; i < n1; i++) {
		int n3;
		cin >> n3;
		v1[i] = n3;
	}
	sort(v1.begin(), v1.end());
}

void DFS(int count, int next) {
	if (count == n2) {
		for (int i = 0; i < n2; i++) {
			cout << v3[i] << ' ';
		}
		cout << endl;
		return;
	}

	for (int i = next; i < n1; i++) {
		v3[count] = v1[i];
		DFS(count + 1, i + 1);
	}
}

void Solution(void) {
	DFS(0, 0);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}