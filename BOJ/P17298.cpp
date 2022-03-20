// ũ�Ⱑ N�� ����
// ��ū���� �����ʿ� �����鼭 i��° ���Һ��� ū �� �߿��� ���� ���ʿ� �ִ� ��
#include <iostream>
#include <stack>
using namespace std;

int a[1000001];
int b[1000001];
int main() {
	int N;
	cin >> N;

	stack<int> s1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s1.empty() && a[i] >= s1.top()) {
			s1.pop();
		}

		if (s1.empty()) {
			b[i] = -1;
		}
		else {
			b[i] = s1.top();
		}

		s1.push(a[i]);
	}

	for (int i = 0; i < N; i++) {
		cout << b[i] << ' ';
	}
	

	return 0;
}