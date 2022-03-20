#include <iostream>
#include <string>
using namespace std;

int main() {
	int test, height, width, number;
	cin >> test;

	while (test != 0) {
		cin >> height >> width >> number;
		int rear = number / height;
		int front = number % height;
		
		if (front != 0) rear++;
		if (front == 0) front = height;

		if (rear / 10 != 0) {
			cout << to_string(front) + to_string(rear) << endl;
		}
		else {
			cout << to_string(front) + '0' + to_string(rear) << endl;
		}
		test--;
	}

	return 0;
}