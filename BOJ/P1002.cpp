#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int testCase;
	cin >> testCase;
	for (int i = 0; i < testCase; i++) {
		ll x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		ll distance = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		ll sumRadius = (r1 + r2) * (r1 + r2);
		ll subRadius = (r1 - r2) * (r1 - r2);
		if (!distance) { // 동심원
			cout << (r1 == r2 ? -1 : 0) << "\n";
			continue;
		}
		if (distance == sumRadius || distance == subRadius) { // 외접원 or 내접원
			cout << 1 << "\n";
			continue;
		}
		if (distance > sumRadius || distance < subRadius) {
			cout << 0 << "\n";
			continue;
		}
		cout << 2 << "\n";
		continue;
	}
}

//참고: https://seongjuk.tistory.com/entry/BOJ-%EB%B0%B1%EC%A4%80-1002%EB%B2%88-%ED%84%B0%EB%A0%9B