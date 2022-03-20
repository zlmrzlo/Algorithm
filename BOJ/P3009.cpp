#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int left[3], right[3];
	vector<pair<int, int>> leftVector(2), rightVector(2);

	for (int i = 0; i < 3; i++) {
		cin >> left[i] >> right[i];
	}

	for (int i = 0; i < 3; i++) {
		if (left[0] == left[i]) {
			leftVector[0].first = left[0];
			leftVector[0].second++;
		}
		else {
			leftVector[1].first = left[i];
			leftVector[1].second++;
		}
		if (right[0] == right[i]) {
			rightVector[0].first = right[0];
			rightVector[0].second++;
		}
		else {
			rightVector[1].first = right[i];
			rightVector[1].second++;
		}
	}

	for (int i = 0; i < 2; i++) {
		if (leftVector[i].second == 1) {
			cout << leftVector[i].first << " ";
		}
	}
	for (int i = 0; i < 2; i++) {
		if (rightVector[i].second == 1) {
			cout << rightVector[i].first;
		}
	}

	return 0;
}