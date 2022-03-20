#include <iostream>
using namespace std;

int main() {
	// 5킬로를 일단 최대한 획득하고 하나씩 빼면서
	// 3킬로 개수를 구한다.

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


// 분석
// 어차피 결국 다 빼면 0이 되어야 하니까
// 큰 수로 나머지 0이 되는지 확인하고 아니면 작은 수로 조금씩 뺀다.
// 설탕이 0이거나 0보다 작은 값을 가지게 되고
// 이걸 바탕으로 화면에 출력하면 된다.

//// 다른 사람이 잘한 것
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