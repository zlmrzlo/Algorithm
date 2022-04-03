#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1e6

int n1;
int	n2;
bool a1[10];
void Input() {
	cin >> n1 >> n2;
	int n3;
	for (int i = 0; i < n2; i++) {
		cin >> n3;
		a1[n3] = true;
	}
}

bool check(int n) {
	string s1 = to_string(n);
	for (int i = 0; i < s1.size(); i++) {
		if (a1[s1[i] - '0']) {
			return false;
		}
	}
	return true;
}

int n4;
void Solution(void) {
	n4 = abs(n1 - 100);
	for (int i = 0; i <= MAX; i++) {
		if (check(i)) {
			int t1 = abs(n1 - i) + to_string(i).size();
			n4 = min(n4, t1);
		}
	}
	cout << n4 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}