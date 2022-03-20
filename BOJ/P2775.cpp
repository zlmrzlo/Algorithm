#include <iostream>
using namespace std;

int main() {
	// �迭 14x14 ����
	// 0�� ���� ���
	// 0������ �̿��ؼ� ����س���
	int count[15][15] = { 0, };

	for (int i = 0; i < 15; i++) {
		count[0][i] = i + 1;
		count[i][0] = 1;
	}

	for (int i = 1; i < 15; i++) {
		for (int j = 1; j < 15; j++) {
			for (int k = 0; k <= j; k++) {
				count[i][j] += count[i - 1][k];
			}
		}
	}


	//for (int i = 0; i < 15; i++) {
	//	for (int j = 0; j < 15; j++) {
	//		cout << count[i][j] << " ";
	//	}
	//	cout << endl;
	//}

	int testCase;
	int floor, room;
	int result = 0;

	cin >> testCase;

	for (int i = 0; i < testCase; i++) {
		cin >> floor >> room;
		for (int j = 0; j < room; j++) {
			if (floor < 15) {
				result = count[floor][room - 1];
				break;
			}
			else {
				cout << "�־��� ������ �Ѿ�ϴ�!" << endl;
			}
		}
		cout << result << endl;
	}


	return 0;
}