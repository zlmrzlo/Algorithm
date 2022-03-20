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
	// 1. 몇 번째인지 숫자를 입력받음
	int order;
	cin >> order;
	// 2. 규칙에 맞게 숫자를 생성
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
	// 3. 생성된 숫자를 출력
	cout << number-- << endl;


	return 0;
}