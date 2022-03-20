#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string input;
	cin >> input;
	int line;
	cin >> line;

	stack<char> left;
	stack<char> right;

	for (int i = 0; i < input.size(); i++) {
		left.push(input[i]);
	}

	while (line--) {
		char command;
		cin >> command;

		if (command == 'P') {
			char alphabat;
			cin >> alphabat;
			left.push(alphabat);
		}
		else if(command == 'L') {
			if (left.empty()) {
				continue;
			}
			right.push(left.top());
			left.pop();
		}
		else if (command == 'B') {
			if (left.empty()) {
				continue;
			}
			left.pop();
		}
		else if (command == 'D') {
			if (right.empty()) {
				continue;
			}
			left.push(right.top());
			right.pop();
		}
	}

	while (!left.empty()) {
		right.push(left.top());
		left.pop();
	}

	while (!right.empty()) {
		cout << right.top();
		right.pop();
	}


	return 0;
}
// ����: https://intaehwang.tistory.com/32

// ��� �ݷʿ� �� ����Ǵ� �� ������
// Ʋ�ȴٰ� ������ �ڵ�
//#include <iostream>
//#include <string>
//using namespace std;
//
//// �� �ٷ� �� ������ ������ ����
//// ���� �ҹ��ڸ� ��� ����, �ִ� 600000 ���ڱ���
//// ���̰� L�� ���ڿ��� ������, L+1 ��ġ���� Ŀ�� �̵� ����
//// L(Ŀ�� ���� �̵�), D(Ŀ�� ������ �̵�), B(Ŀ�� ���� ����)
//// P $(Ŀ�� ���ʿ� $�� �߰�)
//char sentence[100001];
//int main(void) {
//	string temp1;
//	cin >> temp1;
//	int cursorPosition = temp1.size();
//	int totalSize = temp1.size() + 1;
//	for (int i = 0; i < temp1.size(); i++) {
//		sentence[i] = temp1[i];
//	}
//	int commandCount;
//	cin >> commandCount;
//	while (commandCount--) {
//		string command;
//		cin >> command;
//		if (command == "L") {
//			if (cursorPosition != 0) {
//				cursorPosition -= 1;
//			}
//			else {
//				cursorPosition = 0;
//			}
//		}
//		else if(command == "D"){
//			if (cursorPosition != totalSize - 1) {
//				cursorPosition += 1;
//			}
//			else {
//				cursorPosition = totalSize - 1;
//			}
//		}
//		else if (command == "P") {
//			char plusChar;
//			cin >> plusChar;
//			for (int i = totalSize - 1; i >= cursorPosition; i--) {
//				sentence[i + 1] = sentence[i];
//			}
//			sentence[cursorPosition++] = plusChar;
//			totalSize++;
//		}
//		else if (command == "B") {
//			if (cursorPosition - 1 < 0) {
//				continue;
//			}
//			cursorPosition--;
//
//			for (int i = cursorPosition; i < totalSize; i++) {
//				sentence[i] = sentence[i + 1];
//			}
//			totalSize--;
//		}
//	}
//	
//	for (int i = 0; i < totalSize; i++) {
//		cout << sentence[i];
//	}
//
//	return 0;
//}