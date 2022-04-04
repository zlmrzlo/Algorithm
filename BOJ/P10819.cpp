#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
int n4 = 0;
vector<int> v1;
vector<bool> v2;
vector<int> v3;
void Input() {
	cin >> n1;
	v1.resize(n1);
	v2.resize(n1);
	v3.resize(n1);
	for (int i = 0; i < n1; i++) {
		int n2;
		cin >> n2;
		v1[i] = n2;
	}
	sort(v1.begin(), v1.end());
}

void DFS(int count) {
	if (count == n1) {
		int n3 = 0;
		for (int i = 0; i < n1 - 1; i++) {
			n3 += abs(v3[i] - v3[i + 1]);
		}
		n4 = max(n3, n4);
	}

	for (int i = 0; i < n1; i++) {
		if (!v2[i]) {
			v2[i] = true;
			v3[count] = v1[i];
			DFS(count + 1);
			v2[i] = false;
		}
	}
}

void Solution(void) {
	DFS(0);
	cout << n4 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}