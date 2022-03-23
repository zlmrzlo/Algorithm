#include <bits/stdc++.h>
using namespace std;

int a1[1001]; // 원소 값
int a2[1001]; // i번째 원소까지 구한 가장 긴 수열의 길이
vector<int> v1[1001]; // i번째 원소까지 구한 가장 긴 수열의 벡터의 1차원 배열
vector<int> v2; // 정답 벡터
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i];
	}

	for (int i = 1; i <= n1; i++) {
		a2[i] = 1;
		v1[i].push_back(a1[i]);
		for (int j = i - 1; j >= 1; j--) {
			if (a1[i] > a1[j]) {
				if (a2[i] < a2[j] + 1) {
					v1[i].clear();
					v1[i] = v1[j];
					v1[i].push_back(a1[i]);
					a2[i] = a2[j] + 1;
				}
			}
		}

		if (v2.size() < v1[i].size()) {
			v2 = v1[i];
		}
	}

	cout << v2.size() << endl;
	for (int i = 0; i < v2.size(); i++) {
		cout << v2[i] << ' ';
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}