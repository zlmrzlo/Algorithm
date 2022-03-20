#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {
	int N;
	cin >> N;

	queue<int> queue;
	while (N--) {
		string command;
		cin >> command;
		
		if (command == "push") {
			int number;
			cin >> number;
			queue.push(number);
		}
		else if (command == "pop") {
			if (!queue.empty()) {
				cout << queue.front() << endl;;
				queue.pop();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "size") {
			cout << queue.size() << endl;
		}
		else if (command == "empty") {
			if (queue.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (command == "front") {
			if (!queue.empty()) {
				cout << queue.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (command == "back") {
			if (!queue.empty()) {
				cout << queue.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}

// Âü°í: https://blockdmask.tistory.com/119