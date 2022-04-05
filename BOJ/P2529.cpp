#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
vector<char> v1;
vector<bool> v2(10);
vector<int> v3;
vector<string> v4;
void Input() {
	cin >> n1;
	v1.resize(n1);
	v3.resize(n1 + 1);
	for (int i = 0; i < n1; i++) {
		char c1;
		cin >> c1;
		v1[i] = c1;
	}
}

int n2 = 1e10;
int n3 = 0;
void DFS(int count, int before) {
	if (count == n1) {
		string s1 = "";
		for (int i = 0; i < n1 + 1; i++) {
			s1 += to_string(v3[i]);
		}
		v4.push_back(s1);
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!v2[i]) {
			v2[i] = true;
			if (v1[count] == '<') {
				if (before < i) {
					v3[count + 1] = i;
					DFS(count + 1, v3[count + 1]);
				}
			}
			else {
				if (before > i) {
					v3[count + 1] = i;
					DFS(count + 1, v3[count + 1]);
				}
			}
			v2[i] = false;
		}
	}
}

void Solution(void) {
	for (int i = 0; i < 10; i++) {
		v2[i] = true;
		v3[0] = i;
		DFS(0, v3[0]);
		v2[i] = false;
	}
	cout << v4[v4.size() - 1] << endl;
	cout << v4[0] << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}