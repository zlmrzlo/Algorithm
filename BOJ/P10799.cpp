// 쇠막대기는 자신보다 긴 쇠막대기 위에만 놓일 수 있다.
// 끝점이 겹치지 않도록 한다.
// 긴 쇠막대기를 자르는 레이저는 적어도 하나 존재
// 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않는다.

// ()  (((()())(())()))(())        17
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	string s2;
	cin >> s2;

	int total = 0;
	stack<char> s1;
	for (int i = 0; i < s2.size(); i++) {
		if (s2[i] == '(') {
			s1.push(')');
		}
		else if (s2[i - 1] == '(' && s2[i] == ')') {
			s1.pop();
			total += s1.size();
		}
		else {
			total++;
			s1.pop();
		}
	}

	cout << total << endl;

	return 0;
}

// 참고: https://ijsilver.tistory.com/4