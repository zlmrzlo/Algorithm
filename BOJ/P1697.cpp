#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 2

int n1, n2;
bool a1[MAX];

void Input() {
	cin >> n1 >> n2;
	queue<pair<int, int>> q;
	q.push(make_pair(n1, 0));
	a1[n1] = true;

	int res = 0;
	while (!q.empty()) {
		int now = q.front().first;
		int dis = q.front().second;
		q.pop();
		if (now == n2) {
			res = dis;
			break;
		}

		for (int i = 0; i < 3; i++) {
			int next = now;
			if (i == 0) {
				next--;
			}
			else if (i == 1) {
				next++;
			}
			else {
				next *= 2;
			}
			if (next < 0 || next > 1e5) {
				continue;
			}
			if (!a1[next]) {
				a1[next] = true;
				q.push({ next, dis + 1 });
			}
		}
	}
	cout << res << endl;
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}