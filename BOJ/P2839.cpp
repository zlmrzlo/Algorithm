#include <iostream>
using namespace std;

int main() {
	// 5ų�θ� �ϴ� �ִ��� ȹ���ϰ� �ϳ��� ���鼭
	// 3ų�� ������ ���Ѵ�.

	int totalWeight;
	cin >> totalWeight;
	int countFive = 0;
	int countThree = 0;
	int weightSubtractFive = totalWeight;
	int weightSubtractThree = totalWeight;

	while (weightSubtractFive - 5 >= 0) {
		weightSubtractFive -= 5;
		countFive++;
	}

	//cout << weightSubtractFive << endl;
	//cout << countFive << endl;
	for (int i = countFive; i >= 0; i--) {
		weightSubtractThree -= i * 5;
		countThree = 0;
		while (weightSubtractThree - 3 >= 0) {
			weightSubtractThree -= 3;
			countThree++;
		}
		if (weightSubtractThree == 0) {
			countFive = i;
			break;
		}
		weightSubtractThree = totalWeight;
	}

	if (weightSubtractThree != 0) {
		weightSubtractThree = totalWeight;
		countFive = 0;
		countThree = 0;
		while (weightSubtractThree - 3 >= 0) {
			weightSubtractThree -= 3;
			countThree++;
		}
	}

	if (weightSubtractThree != 0) {
		cout << -1 << endl;
	}
	else {
		cout << countFive + countThree << endl;
	}

	return 0;
}


// �м�
// ������ �ᱹ �� ���� 0�� �Ǿ�� �ϴϱ�
// ū ���� ������ 0�� �Ǵ��� Ȯ���ϰ� �ƴϸ� ���� ���� ���ݾ� ����.
// ������ 0�̰ų� 0���� ���� ���� ������ �ǰ�
// �̰� �������� ȭ�鿡 ����ϸ� �ȴ�.

//// �ٸ� ����� ���� ��
//#include <iostream>
//using namespace std;
//
//int main() {
//	int sugar, a(0);
//	cin >> sugar;
//
//	while (sugar > 0) {
//		if (sugar % 5 == 0) {
//			sugar -= 5;
//			a++;
//		}
//		else {
//			sugar -= 3;
//			a++;
//		}
//	}
//
//	if (sugar == 0)
//		cout << a;
//	else
//		cout << -1;
//
//	return 0;
//}