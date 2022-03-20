#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	cin >> N;

	vector<int> v1(N);
	stack<double> s1;
	string s2;
	cin >> s2;

	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}

	double result = 0;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] >= 'A' && s2[i] <= 'Z') {
			s1.push(v1[s2[i] - 'A']);
		}
		else {
			if (!s1.empty()) {
				double left, right;
				right = s1.top();
				s1.pop();
				left = s1.top();
				if (s2[i] == '+') {
					result = left + right;
				}
				else if (s2[i] == '-') {
					result = left - right;
				}
				else if (s2[i] == '*') {
					result = left * right;
				}
				else if (s2[i] == '/') {
					result = left / right;
				}
				s1.pop();
				s1.push(result);
			}
		}
	}

	cout << fixed;
	cout.precision(2);
	cout << s1.top() << endl;

	return 0;
}

// Âü°í: https://minyeok2ee.gitlab.io/boj/boj-1935/