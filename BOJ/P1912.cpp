#include <bits/stdc++.h>
using namespace std;

#define MAX 100001

int a1[MAX];
int a2[MAX];
void Solution(void) {
	int n1;
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		cin >> a1[i];
		a2[i] = a1[i];
	}

	// 시간 초과
	//int n2 = a1[1];
	//for (int i = 1; i <= n1; i++) {
	//	for (int j = i; j <= n1; j++) {
	//		int n3 = 0;
	//		for (int k = i; k <= j; k++) {
	//			//cout << i << ", " << j << ", " << k << endl;
	//			n3 += a1[k];
	//		}
	//		//cout << n2 << ", " << n3 << endl;
	//		n2 = max(n2, n3);
	//	}
	//}

	int n2 = a2[1];
	for (int i = 2; i <= n1; i++) {
		a2[i] = max(a2[i], a2[i - 1] + a1[i]);
		n2 = max(a2[i], n2);
	}

	cout << n2 << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}

// 참고: https://mtoc.tistory.com/41