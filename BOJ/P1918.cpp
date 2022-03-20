#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string s1;
	cin >> s1;

	stack<char> s2;
	for (int i = 0; i < s1.size(); i++) {
		if (s1[i] >= 'A' && s1[i] <= 'Z') {
			cout << s1[i];
		}
		else {
			if (s1[i] == '(') {
				s2.push(s1[i]);
			}
			else if (s1[i] == '*' || s1[i] == '/') {
				while (!s2.empty() && (s2.top() == '*' || s2.top() == '/')) {
					cout << s2.top();
					s2.pop();
				}
				s2.push(s1[i]);
			}
			else if (s1[i] == '+' || s1[i] == '-') {
				while (!s2.empty() && s2.top() != '(') {
					cout << s2.top();
					s2.pop();
				}
				s2.push(s1[i]);
			}
			else if (s1[i] == ')') {
				while (!s2.empty() && s2.top() != '(') {
					cout << s2.top();
					s2.pop();
				}
				s2.pop();
			}
		}
	}

	if (!s2.empty()) {
		while (!s2.empty()) {
			cout << s2.top();
			s2.pop();
		}
	}
	
	return 0;
}

// Âü°í: https://donggoolosori.github.io/2020/10/19/boj-1918/