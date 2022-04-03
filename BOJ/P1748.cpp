#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
void Input() {
	cin >> n1;
}

int n3;
void Solution(void) {
	for (int i = 1; i <= n1; i *= 10) {
		n3 += n1 - i + 1;
	}
	cout << n3 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}