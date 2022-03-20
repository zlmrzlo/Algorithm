#include <iostream>
using namespace std;

int main() {
	int index;
	cin >> index;
	int count = 1;
	int subtract = 1;

	while (true) {
		if (index - subtract <= 0) {
			//cout << subtract << endl;
			break;
		}
		else {
			count++;
			subtract += count;
		}
	}

	//cout << count << endl;

	if (count % 2 == 0) {
		cout << count - (subtract - index) << "/" << (subtract - index) + 1 << endl;
	}
	else {
		cout << (subtract - index) + 1 << "/" << count - (subtract - index) << endl;
	}
	return 0;
}