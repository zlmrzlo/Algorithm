#include <bits/stdc++.h>
using namespace std;

/*
17 8
2
2 16
*/
/*
6 2
*/
void Solution(void) {
	int n1, n2;
	cin >> n1 >> n2;
	int n3;
	cin >> n3;

	vector<int> v1;
	while (n3--) {
		int n4;
		cin >> n4;
		v1.push_back(n4);
	}

	int n5 = 0;
	for (int i = 0; i < v1.size(); i++) {
		n5 += v1[i] * pow(n1, v1.size() - i - 1);
	}

	vector<int> v2;
	while (n5 != 0) {
		int n6 = n5 % n2;
		v2.push_back(n6);
		n5 /= n2;
	}

	for (int i = v2.size() - 1; i >= 0; i--) {
		cout << v2[i] << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}