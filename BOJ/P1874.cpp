#include <iostream>
#include <stack>
using namespace std;

int main(void) {
	int stackCount;
	cin >> stackCount;

	stack<int> stack;
	string result = "";
	int sequence = 1;
	int number;
	while (stackCount--) {
		cin >> number;
		if (number >= sequence) {
			while (number >= sequence) {
				stack.push(sequence++);
				result += "+\n";
			}
			stack.pop();
			result += "-\n";
		}
		else {
			if (stack.top() == number) {
				stack.pop();
				result += "-\n";
			}
			else {
				result = "NO";
				break;
			}
		}
	}
	cout << result;
		
	return 0;
}

// 참고: https://guiyum.tistory.com/3
// 참고: https://congcoding.tistory.com/53