// �踷���� �ڽź��� �� �踷��� ������ ���� �� �ִ�.
// ������ ��ġ�� �ʵ��� �Ѵ�.
// �� �踷��⸦ �ڸ��� �������� ��� �ϳ� ����
// �������� � �踷����� �� �������� ��ġ�� �ʴ´�.

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

// ����: https://ijsilver.tistory.com/4