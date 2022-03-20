#include <iostream>
#include <vector>
using namespace std;
int synergy[20][20];
bool team[20];
int number;
int minResult = 100000000;

void Match(int count, int index) {
	vector<int> start;
	vector<int> link;
	int startScore = 0;
	int linkScore = 0;
	if (count == number / 2) {
		for (int i = 0; i < number; i++) {
			if (team[i]) {
				start.push_back(i);
			}
			else {
				link.push_back(i);
			}
		}
		for (int i = 0; i < number/2; i++) {
			for (int j = 0; j < number/2; j++) {
				startScore += synergy[start[i]][start[j]];
				linkScore += synergy[link[i]][link[j]];
			}
		}
		if (abs(startScore - linkScore) < minResult) {
			minResult = abs(startScore - linkScore);
		}
		return;
	}
	for (int i = index; i < number; i++) {
		if (team[i]) {
			continue;
		}
		else {
			team[i] = true;
			Match(count + 1, i);
			team[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> number;
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cin >> synergy[i][j];
		}
	}
	Match(0, 0);
	cout << minResult << endl;

	return 0;
}

// Âü°í : https://cryptosalamander.tistory.com/61