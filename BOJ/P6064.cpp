#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 4e4

int n1;
int n2, n3, n4, n5;
void Input() {
	cin >> n1;
}

int GCD(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return GCD(n2, n1 % n2);
	}
}

int LCM(int a, int b) {
	return a * b / GCD(a, b);
}

void Solution(void) {
	for (int i = 0; i < n1; i++) {
		cin >> n2 >> n3 >> n4 >> n5;
		int n6 = n4 - 1;
		int n8 = n5 - 1;
		int n7 = LCM(n2, n3);
		while (true) {
			if (n6 > n7) {
				n6 = -1;
				break;
			}
			if (n6 % n3 == n8) {
				n6++;
				break;
			}
			n6 += n2;
		}
		cout << n6 << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}