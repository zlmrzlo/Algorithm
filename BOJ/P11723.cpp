#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n1;
int a2[21];
bool a1[21];
void Input() {
	cin >> n1;
	while (n1--) {
		string s1;
		cin >> s1;
		if (s1 == "add") {
			int n1;
			cin >> n1;
			if (!a1[n1]) {
				a2[n1] = n1;
				a1[n1] = true;
			}
		}
		else if (s1 == "remove") {
			int n1;
			cin >> n1;
			if (a1[n1]) {
				a2[n1] = 0;
				a1[n1] = false;
			}
		}
		else if (s1 == "check") {
			int n1;
			cin >> n1;
			if (a1[n1]) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (s1 == "toggle") {
			int n1;
			cin >> n1;
			if (a1[n1]) {
				a2[n1] = 0;
				a1[n1] = false;
			}
			else {
				a2[n1] = n1;
				a1[n1] = true;
			}
		}
		else if (s1 == "all") {
			for (int i = 1; i <= 20; i++) {
				a1[i] = true;
				a2[i] = i;
			}
		}
		else if (s1 == "empty") {
			for (int i = 1; i <= 20; i++) {
				a1[i] = false;
				a2[i] = 0;
			}
		}
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