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

	while (true) {
		int n1 = 0;
		for (int i = 0; i < 3; i++) {
			if (!s2.empty()) {
				n1 += s2.top() * pow(2, i);
				s2.pop();
			}
		}
		s3.push(n1);
		if (s2.empty()) {
			break;
		}
	}

	while (!s3.empty()) {
		cout << s3.top();
		s3.pop();
	}

	return 0;
}