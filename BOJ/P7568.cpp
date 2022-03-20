#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL);
	int count;
	cin >> count;
	int* kg = new int[count];
	int* cm = new int[count];
	int* rank = new int[count];

	for (int i = 0; i < count; i++) {
		rank[i] = 1;
	}

	for (int i = 0; i < count; i++) {
		cin >> kg[i] >> cm[i];
	}

	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count; j++) {
			if (kg[i] < kg[j] && cm[i] < cm[j]) {
				rank[i]++;
			}
		}
	}

	for (int i = 0; i < count; i++) {
		cout << rank[i] << " ";
	}

	return 0;
}