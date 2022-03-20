#include <iostream>
using namespace std;

int main() {
	int position;
	int count = 1;

	cin >> position;

	while (position != 1) {
		if (position - 6 * count <= 0) {
			count++;
			break;
		}
		else {
			position -= 6 * count;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}