#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
vector<int> v1;
void Input() {
	cin >> n1;

	v1.resize(n1);
	for (int i = 0; i < n1; i++) {
		int n2;
		cin >> n2;
		v1[i] = n2;
	}
}

bool PreviousPermutation() {
	int i = n1 - 1;
	while (i > 0 && v1[i - 1] < v1[i]) {
		i--;
	}

	if (i <= 0) {
		return false;
	}

	int j = n1 - 1;
	while (v1[i - 1] < v1[j]) {
		j--;
	}

	swap(v1[i - 1], v1[j]);

	j = n1 - 1;
	while (j > i) {
		swap(v1[i], v1[j]);
		i++;
		j--;
	}
	return true;
}

void Solution(void) {
	if (PreviousPermutation()) {
		for (int i = 0; i < n1; i++) {
			cout << v1[i] << ' ';
		}
	}
	else {
		cout << -1 << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}