#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void) {
	int number;
	cin >> number;
	stack<int> stack;
	string command;

	while (number != 0) {
		cin >> command;
		if (command == "push") {
			int x;
			cin >> x;
			stack.push(x);
		}
		else if (command == "pop") {
			if (!stack.empty()) {
				cout << stack.top() << '\n';
				stack.pop();
			}
			else {
				cout << -1 << '\n';
			}
		}
		else if (command == "size") {
			cout << stack.size() << '\n';
		}
		else if (command == "empty") {
			if (stack.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (command == "top") {
			if (!stack.empty()) {
				cout << stack.top() << '\n';
			}
			else {
				cout << -1 << '\n';
			}
		}
		
		number--;
	}

	return 0;
}