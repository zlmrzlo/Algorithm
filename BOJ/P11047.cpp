#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 10

int coin_count, coin_total;
int coin_value[MAX];
int coin_min_count;

void Input() {
	cin >> coin_count >> coin_total;

	for (int i = 0; i < coin_count; i++) {
		cin >> coin_value[i];
	}
}

void Solution(void) {
	for (int i = coin_count - 1; i >= 0 ; i--) {
		coin_min_count += coin_total / coin_value[i];
		coin_total %= coin_value[i];
	}

	cout << coin_min_count << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}