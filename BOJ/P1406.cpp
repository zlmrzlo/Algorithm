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
// 참고: https://intaehwang.tistory.com/32

// 모든 반례에 다 적용되는 것 같은데
// 틀렸다고 나오는 코드
//#include <iostream>
//#include <string>
//using namespace std;
//
//// 한 줄로 된 간다한 에디터 구현
//// 영어 소문자만 기록 가능, 최대 600000 글자까지
//// 길이가 L인 문자열이 있으면, L+1 위치까지 커서 이동 가능
//// L(커서 왼쪽 이동), D(커서 오른쪽 이동), B(커서 왼쪽 삭제)
//// P $(커서 왼쪽에 $를 추가)
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