#include <iostream>
#include <vector>

using namespace std;

void mySort(vector<int>& sortNumber, int count) {
	for (int i = 0; i < count - 1; i++) {
		for (int j = i; j < count; j++) {
			if (sortNumber[i] > sortNumber[j]) {
				swap(sortNumber[i], sortNumber[j]);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);

	// 1. ���� �� ������ �Է� ����
	int count;
	cin >> count;
	vector<int> sortNumber(count);

	for (int i = 0; i < count; i++) {
		cin >> sortNumber[i];
	}

	//for (int i = 0; i < count; i++) {
	//	cout << sortNumber[i] << '\n';
	//}

	// 2. ����
	mySort(sortNumber, count);

	// 2. �������� ���
	for (int i = 0; i < count; i++) {
		cout << sortNumber[i] << '\n';
	}

	return 0;
}