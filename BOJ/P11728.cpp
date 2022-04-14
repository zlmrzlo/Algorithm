#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void Input() {
	int size_a, size_b;
	cin >> size_a >> size_b;
	vector<int> c(size_a + size_b, 0);
	for (int i = 0; i < size_a; i++) {
		cin >> c[i];
	}

	for (int i = 0; i < size_b; i++) {
		cin >> c[size_a + i];
	}

	sort(c.begin(), c.end());

	for (int i = 0; i < size_a + size_b; i++) {
		cout << c[i] << ' ';
	}
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}