#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 1

int n1, n2;
bool a1[MAX];

void Input() {
	cin >> n1 >> n2;
	queue<pair<int, int>> q;
	q.push(make_pair(n1, 0));

	while (!q.empty()) {
		int now = q.front().first;
		int time = q.front().second;
		a1[now] = true;
		q.pop();


		if (now == n2) {
			cout << time << endl;
			return;
		}

		if (now >= 0 and now < MAX) {
			if (now * 2 < MAX) {
				if (!a1[now * 2]) {
					a1[now * 2] = true;
					q.push({ now * 2, time });
				}
			}

			if (now - 1 >= 0) {
				if (!a1[now - 1]) {
					a1[now - 1] = true;
					q.push({ now - 1, time + 1 });
				}
			}

			if (now + 1 < MAX) {
				if (!a1[now + 1]) {
					a1[now + 1] = true;
					q.push({ now + 1, time + 1 });
				}
			}
		}
	}
}

void Solution(void) {
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}
