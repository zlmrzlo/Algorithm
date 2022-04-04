#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1, n2;
vector<char> v1;
vector<bool> v2;
vector<char> v3;
void Input() {
	cin >> n1 >> n2;
	v1.resize(n2);
	v2.resize(n2);
	v3.resize(n1);
	for (int i = 0; i < n2; i++) {
		char n3;
		cin >> n3;
		v1[i] = n3;
	}
	sort(v1.begin(), v1.end());
}

void DFS(int count, int next) {
	if (count == n1) {
		int n4 = 0, n5 = 0;
		for (int i = 0; i < n1; i++) {
			if (v3[i] == 'a' || v3[i] == 'e' || v3[i] == 'o' || v3[i] == 'u' || v3[i] == 'i') {
				n4++;
			}
			else {
				n5++;
			}
		}

		if (n5 >= 2 && n4 >= 1) {
			for (int i = 0; i < n1; i++) {
				cout << v3[i];
			}
			cout << endl;
		}
		return;
	}

	for (int i = next; i < n2; i++) {
		if (!v2[i]) {
			v2[i] = true;
			v3[count] = v1[i];
			DFS(count + 1, i + 1);
			v2[i] = false;
		}
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