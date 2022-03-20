#include <iostream>
using namespace std;

int tile[1000001];

int TileCheck(int number) {
	if (number == 1) {
		return 1;
	}
	else if (number == 2) {
		return 2;
	}
	else {
		if (tile[number] != 0) {
			return tile[number];
		}
		else {
			tile[number] = (TileCheck(number - 1) + TileCheck(number - 2)) % 15746;
			return tile[number];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int number;
	cin >> number;
	cout << TileCheck(number);

	return 0;
}