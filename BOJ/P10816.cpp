#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)5e5 + 1

vector<int> card;
vector<int> check;
vector<int> answer;
int size_a, size_b;

void Input() {
	cin >> size_a;
	card.resize(size_a);
	for (int i = 0; i < size_a; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> size_b;
	check.resize(size_b);
	answer.resize(size_b);
	for (int i = 0; i < size_b; i++) {
		cin >> check[i];

		auto upper = upper_bound(card.begin(), card.end(), check[i]);
		auto lower = lower_bound(card.begin(), card.end(), check[i]);
		answer[i] = upper - lower;
	}
}

void Solution(void) {
	for (int i = 0; i < size_b; i++) {
		cout << answer[i] << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}