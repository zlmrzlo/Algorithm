#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int testcase;
	cin >> testcase;

	while (testcase--) {
		string parenthesis;
		cin >> parenthesis;
		stack<char> stack;
		string answer = "YES";
		for (int i = 0; i < parenthesis.size(); i++) {
			if (parenthesis[i] == '(') {
				stack.push(parenthesis[i]);
			}
			else if(!stack.empty() && parenthesis[i] == ')'){
				stack.pop();
			}
			else {
				answer = "NO";
				break;
			}
		}
		if (!stack.empty()) {
			answer = "NO";
		}

		cout << answer << endl;
	}

	return 0;
}

// Âü°í : https://seoftware.tistory.com/21