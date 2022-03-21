#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

int main(void) {
	string s1;
	cin >> s1;

	stack<int> s2;
	stack<int> s3;
	for (int i = 0; i < s1.size(); i++) {
		s2.push(s1[i] - '0');
	}

	if (s2.size() == 1 && s2.top() == 0) {
		cout << s2.top();
		s2.pop();
		return 0;
	}

	while (!s2.empty()) {
		int n1 = s2.top();
		s2.pop();
		int i1 = 0;
		int n2;
		while (i1 != 3) {
			n2 = n1 % 2;
			s3.push(n2);
			n1 /= 2;
			i1++;
		}
	}

	bool f1 = false;
	while (!s3.empty() && !f1) {
		if (s3.top() == 0) {
			s3.pop();
		}
		else {
			f1 = true;
		}
	}

	while (!s3.empty()) {
		cout << s3.top();
		s3.pop();
	}

	return 0;
}