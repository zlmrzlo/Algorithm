// 크기가 N인 수열
// 오큰수는 오른쪽에 있으면서 등장한 횟수가 i번째 원소보다 큰 수 중에서 가장 왼쪽에 있는 수
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int a[1000001]; // 입력 배열
int b[1000001]; // 출력 배열
int c[1000001]; // 등장한 숫자의 개수
int main() {
	int N;
	cin >> N;

	stack<int> s1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		c[a[i]]++;
	}

	for (int i = N - 1; i >= 0; i--) {
		while (!s1.empty() && c[a[i]] >= c[s1.top()]) {
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