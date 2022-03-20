#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	int card;
	cin >> card;
	int limit;
	cin >> limit;
	vector<int> cardVector(card);

	for (int i = 0; i < cardVector.size(); i++) {
		cin >> cardVector[i];
		//cout << cardVector[i] << " ";
	}

	int max = 0;
	for (int i = 0; i < cardVector.size() - 2; i++) {
		for (int j = i + 1; j < cardVector.size() - 1; j++) {
			for (int k = j + 1; k < cardVector.size(); k++) {
				if (cardVector[i] + cardVector[j] + cardVector[k] <= limit) {
					if (max < cardVector[i] + cardVector[j] + cardVector[k]) {
						max = cardVector[i] + cardVector[j] + cardVector[k];
					}
				}
			}
		}
	}

	cout << max << '\n';

	return 0;
}