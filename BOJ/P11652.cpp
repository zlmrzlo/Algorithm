#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

typedef long long ll;

vector<ll> card;

void Input() {
	int card_size;
	cin >> card_size;
	card.resize(card_size);
	for (int i = 0; i < card_size; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	int result = 0;
	long long result_number = card[0];
	int count = 0;
	for (int i = 1; i < card.size(); i++) {
		if (card[i] == card[i - 1]) {
			count++;
			if (result < count) {
				result_number = card[i];
				result = count;
			}
		}
		else {
			count = 0;
		}
	}
	cout << result_number << endl;
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}