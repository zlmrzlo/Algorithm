#include <iostream>
#include <string>

using namespace std;

bool IsSix(int number) {
	bool isSix = false;
	while (number != 0) {
		if (number % 10 == 6) {
			if (number / 10 % 10 == 6) {
				if (number / 10 / 10 % 10 == 6) {
					isSix = true;
				}
			}
		}
		number /= 10;
	}
	return isSix;
}

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	// 1. �� ��°���� ���ڸ� �Է¹���
	int order;
	cin >> order;
	// 2. ��Ģ�� �°� ���ڸ� ����
	//cout << IsSix(order) << endl;

	int number = 666;
	while (order != 0) {
		if (order == 1) {
			break;
		}
		number++;
		if (IsSix(number)) {
			order--;
		}
	}
	// 3. ������ ���ڸ� ���
	cout << number-- << endl;


	return 0;
}