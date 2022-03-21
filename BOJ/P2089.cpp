#include <bits/stdc++.h>
using namespace std; 

void Solution() {
	int n1;
	cin >> n1;

	if (n1 == 0) {
		cout << '0';
		return;
	}

	string s1 = "";
	while (n1 != 0) {
		if (n1 % -2 == 0) {
			s1 += "0";
			n1 /= -2;
		}
		else {
			s1 += "1";
			n1 = (n1 - 1) / -2;
		}
	}

	reverse(s1.begin(), s1.end());

	cout << s1 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// Âü°í : https://minyeok2ee.gitlab.io/boj/boj-2089/