// 요세푸스 문제
// 1. 1번부터 N번까지 원을 이루면서 앉아있음
//    양의 정수 K가 주어진다.
// 2. K번째 사람을 제거한다.
// 3. N명의 사람이 모두 제거될 때까지 제거한다.
// 4. (N, K) 요세푸스 순열
// (7, 3) -> <3, 6, 2, 7, 5, 1, 4>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 1 2 3 4 5 6 7
// 1 2 4 5 6 7
// 1 2 4 5 7
// 1 4 5 7
// 1 4 5
// 1 4

queue<int> q1;
vector<int> v1;

int eliminate(int number) {
	int temp;
	for (int i = 0; i < number - 1; i++) {
		temp = q1.front();
		q1.pop();
		q1.push(temp);
	}
	int result = q1.front();
	q1.pop();
	return result;
}

int main(void) {
	int N, K;
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		q1.push(i);
	}

	while (N--) {
		if (!q1.empty()) {
			v1.push_back(eliminate(K));
		}
	}

	cout << '<';
	for (int i = 0; i < v1.size() - 1; i++) {
		cout << v1[i] << ", ";
	}
	cout << v1[v1.size() - 1] << '>';
	
	return 0;
}