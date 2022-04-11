#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e3 + 1

int target;
bool visited[MAX][MAX];
queue<tuple<int, int, int>> q;
void Input() {
	cin >> target;
}

void BFS() {
	q.push({ 1, 0, 0 });
	visited[1][0] = true;

	while (!q.empty()) {
		int current = get<0>(q.front());
		int clip = get<1>(q.front());
		int time = get<2>(q.front());
		q.pop();

		if (current == target) {
			cout << time << endl;
			return;
		}

		if (current > 0 && current < MAX) {
			if (!visited[current][current]) {
				visited[current][current] = true;
				q.push({ current, current, time + 1 });
			}

			if (clip > 0 && current + clip < MAX) {
				if (!visited[current + clip][clip]) {
					visited[current + clip][clip] = true;
					q.push({ current + clip, clip, time + 1 });
				}
			}

			if (!visited[current - 1][clip]) {
				visited[current - 1][clip] = true;
				q.push({ current - 1, clip, time + 1 });
			}
		}
	}
}

void Solution(void) {
	BFS();
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}