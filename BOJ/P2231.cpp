#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int number;
	cin >> number;
	int count = 0;
	int input = number;
	while (number != 0) {
		number /= 10;
		count++;
	}

	vector<int> position(count);
	int forCount = 0;
	int sum = 0;
	int creater = 0;
	for (int i = input - 10 * count; i < input; i++) {
		forCount = 0;
		sum = 0;
		creater = i;
		while (creater != 0) {
			position[forCount] = creater % 10;
			creater /= 10;
			forCount++;
		}

		for (int j = 0; j < position.size(); j++) {
			sum += position[j];
		}
		sum += i;

		if (sum == input) {
			cout << i << '\n';
			break;
		}
	}

	if (sum != input) {
		cout << 0 << '\n';
	}

	return 0;
}