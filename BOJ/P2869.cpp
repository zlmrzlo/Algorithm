#include <iostream>
using namespace std;

int main() {
	int up, down, target;
	cin >> up >> down >> target;
	int softTarget = target - up;
	int day = (int)(softTarget/(up - down)) - 1;
	int current = (up - down) * day;

	while (current < target) {
		current += up;
		day++;

		if (current >= target) {
			break;
		}

		current -= down;
	}
	cout << day << endl;

	return 0;
}