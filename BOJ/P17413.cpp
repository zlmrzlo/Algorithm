#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 공백을 만나면 그동안 스택에 저장한 정보를 꺼낸다.
// <를 만나면 >를 만날 때까지 출력
// 문자열 끝이면 그동안 스택에 저장한 정보를 꺼낸다.


int main(void) {
	string s1;
	getline(cin, s1);
	
	stack<char> s2;
	for (int n1 = 0; n1 < s1.size(); n1++) {

		if (s1[n1] == '<') {
			while (s1[n1] != '>') {
				cout << s1[n1];
				n1++;
			}
			cout << s1[n1]; 
			continue;
		}
		else {
			s2.push(s1[n1]);
			if (s1[n1 + 1] == '<' || s1[n1 + 1] == ' ' || n1 == s1.size() - 1) {
				while (!s2.empty()) {
					cout << s2.top();
					s2.pop();
				}
				if (s1[n1 + 1] == ' ') {
					cout << ' ';
					n1++;
				}
			}
		}
	}

	return 0;
}