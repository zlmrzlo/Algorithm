#include <bits/stdc++.h>
using namespace std;

void Solution(void) {
	string s1;
	int n1;
	
	cin >> s1 >> n1;

	int i1 = 0;
	int n2 = 0;
	while (i1 < s1.size()) {
		if (s1[i1] >= '0' && s1[i1] <= '9') {
			int n3 = s1[i1] - '0';
			n2 += n3 * pow(n1, s1.size() - 1 - i1);
		}
		else if (s1[i1] >= 'A' && s1[i1] <= 'Z') {
			int n3 = s1[i1] - 'A' + 10;
			n2 += n3 * pow(n1, s1.size() - 1 - i1);
		}

		i1++;
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}