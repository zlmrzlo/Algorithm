#include <iostream>
#include <vector>
using namespace std;
int inputCount;
vector<int> input;
vector<int> inputOperator;
int minimum = 1000000001;
int maximum = -1000000001;

void BackTracking(int count, int sum, int plus, int minus, int multiple, int divide) {
	if (count == inputCount - 1) {
		if (plus > 0) {
			sum += input[count];
		}
		else if (minus > 0) {
			sum -= input[count];
		}
		else if (multiple > 0) {
			sum *= input[count];
		}
		else {
			sum /= input[count];
		}
		minimum = min(sum, minimum);
		maximum = max(sum, maximum);
		return;
	}

	if (plus > 0) {
		BackTracking(count + 1, sum + input[count], plus - 1, minus, multiple, divide);
	}
	if (minus > 0) {
		BackTracking(count + 1, sum - input[count], plus, minus - 1, multiple, divide);
	}
	if (multiple > 0) {
		BackTracking(count + 1, sum * input[count], plus, minus, multiple - 1, divide);
	}
	if (divide > 0) {
		BackTracking(count + 1, sum / input[count], plus, minus, multiple, divide - 1);
	}

}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> inputCount;
	for (int i = 0; i < inputCount; i++) {
		int temp;
		cin >> temp;
		input.push_back(temp);
	}

	for (int i = 0; i < 4; i++) {
		int temp;
		cin >> temp;
		inputOperator.push_back(temp);
	}
	int sum = input[0];
	BackTracking(1, sum, inputOperator[0], inputOperator[1], inputOperator[2], inputOperator[3]);
	cout << maximum << '\n';
	cout << minimum << '\n';
	return 0;
}

// Âü°í : https://www.acmicpc.net/board/view/75502