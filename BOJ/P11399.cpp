#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e3 + 1

int human_size;
bool human_check[MAX];

vector<pair<int, int>> human;

void Input() {
	cin >> human_size;

	int temp;
	for (int i = 0; i < human_size; i++) {
		cin >> temp;
		human.push_back({ temp, i });
	}

	sort(human.begin(), human.end());

	int min_delay = 0;
	for (int i = 0; i < human_size; i++) {
		min_delay += human[i].first * (human_size - i);
	}

	cout << min_delay << endl;
}

void Solution(void) {
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}