#include <bits/stdc++.h>
using namespace std;

void Solution(void) {
	int n1 ,n2;
	cin >> n1 >> n2;
	
	string s1;
	while (n1 != 0) {
		int n3 = n1 % n2;
		if (n3 >= 10) {
			char c1 = 'A' + n3 - 10;
			s1 += c1;
		}
		else {
			s1 += to_string(n3);
		}
		n1 /= n2;
	}
	
	reverse(s1.begin(), s1.end());

	cout << s1 << endl;

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}