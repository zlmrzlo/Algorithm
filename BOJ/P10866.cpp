#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void) {
	string c1;
	int n1;
	int n2;

	cin >> n1;
	deque<int> d1;
	while (n1--) {
		cin >> c1;

		if (c1 == "push_front") {
			cin >> n2;
			d1.push_front(n2);
		}
		else if (c1 == "push_back") {
			cin >> n2;
			d1.push_back(n2);
		}
		else if (c1 == "pop_front") {
			if (!d1.empty()) {
				cout << d1.front() << endl;
				d1.pop_front();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (c1 == "pop_back") {
			if (!d1.empty()) {
				cout << d1.back() << endl;
				d1.pop_back();
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (c1 == "size") {
			cout << d1.size() << endl;
		}
		else if (c1 == "empty") {
			if (d1.empty()) {
				cout << 1 << endl;
			}
			else {
				cout << 0 << endl;
			}
		}
		else if (c1 == "front") {
			if (!d1.empty()) {
				cout << d1.front() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
		else if (c1 == "back") {
			if (!d1.empty()) {
				cout << d1.back() << endl;
			}
			else {
				cout << -1 << endl;
			}
		}
	}

	return 0;
}