#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> v1(9);
int n1;
void Input(void) {
	for (int i = 0; i < v1.size(); i++) {
		cin >> v1[i];
		n1 += v1[i];
	}
}

void Solution() {
	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++) {
		for (int j = i + 1; j < v1.size(); j++) {
			if (n1 - v1[i] - v1[j] == 100) {
				for (int k = 0; k < v1.size(); k++) {
					if (k == i || k == j) {
						continue;
					}
					cout << v1[k] << endl;
				}
				return;
			}
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}

// Âü°í: https://guiyum.tistory.com/25