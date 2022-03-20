#include <iostream>
#include <vector>
using namespace std;
#define MAX 8

int N, M;
vector<int> number(MAX);
//vector<bool> visited(MAX);

void BackTracking(int count) {
	if (count == M) {
		for (int i = 0; i < M; i++) {
			cout << number[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		number[count] = i;
		BackTracking(count + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cout.tie(NULL), cin.tie(NULL);
	cin >> N >> M;

	BackTracking(0);

	return 0;
}

// ���� : https://hongchan.tistory.com/5