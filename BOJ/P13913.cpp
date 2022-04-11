#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 2

int n1, n2;
bool a1[MAX];
int a2[MAX];
vector<int> v1;
vector<int> v2;
int res;

void Input() {
	cin >> n1 >> n2;
	queue<pair<int, int>> q;
	q.push(make_pair(n1, 0));

	while (!q.empty()) {
		int now = q.front().first;
		int dis = q.front().second;
		a1[now] = true;
		q.pop();
		if (now == n2) {
			int idx = now;
			while (idx != n1) {
				v2.push_back(idx);
				idx = a2[idx];
			}
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
				a2[next] = now;
			}
		}
	}
	cout << res << endl;
	cout << n1 << ' ';
	for (int i = v2.size() - 1; i >= 0 ; i--) {
		cout << v2[i] << ' ';
	}
}

//bool b1;
//void DFS(int count, int node) {
//	if (b1) {
//		return;
//	}
//	if (count == res && node == n2) {
//		b1 = true;
//		for (int i = 0; i < v1.size(); i++) {
//			cout << v1[i] << ' ';
//		}
//		cout << endl;
//		return;
//	}
//	a1[node] = true;
//
//	for (int i = 0; i < 3; i++) {
//		int next = node;
//		if (i == 0) {
//			next++;
//		}
//		else if (i == 1) {
//			next--;
//		}
//		else {
//			next *= 2;
//		}
//
//		if (next < 0 || next > 1e5) {
//			continue;
//		}
//
//		if (next > n2) {
//			continue;
//		}
//
//		if (!a1[next]) {
//			a1[next] = true;
//			v1.push_back(next);
//			DFS(count + 1, next);
//			v1.pop_back();
//			a1[next] = false;
//		}
//	}
//}

void Solution(void) {
	//memset(a1, false, sizeof(a1));
	//cout << n1 << ' ';
	//DFS(0, n1);
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}