#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 1

vector<int> v1[MAX];
queue<int> q1;
bool a1[MAX];
int n1;

bool BFS() {
	if (q1.front() != 1) {
		return false;
	}

	queue<int> q2;
	q2.push(1);
	q1.pop();

	while (!q2.empty()) {
		int now = q2.front();
		q2.pop();
		a1[now] = true;

		int next_cnt = v1[now].size();
		for (int next : v1[now]) {
			if (a1[next]) {
				next_cnt--;
			}
		}

		while (next_cnt) {
			auto it_next = find(v1[now].begin(), v1[now].end(), q1.front());
			if (it_next != v1[now].end()) {
				q2.push(*it_next);
				q1.pop();
				next_cnt--;
			}
			else {
				return false;
			}
		}
	}
	return true;
}

void Input() {
	cin >> n1;
	int n2, n3;
	for (int i = 0; i < n1 - 1; i++) {
		cin >> n2 >> n3;
		v1[n2].push_back(n3);
		v1[n3].push_back(n2);
	}

	int n4;
	for (int i = 0; i < n1; i++) {
		cin >> n4;
		q1.push(n4);
	}

	cout << BFS();
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}


// 다른 풀이
//#include <iostream>
//#include <queue>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//
//int n, a, b;
//vector<int> v[100001];
//queue<int> order;
//int bfs[100001];
//
//bool comp(const int& a, const int& b) {
//	return bfs[a] < bfs[b];
//}
//int main() {
//	cin.tie(0);
//	cin.sync_with_stdio(0);
//
//	cin >> n;
//	for (int i = 0; i < n - 1; i++) {
//		cin >> a >> b;
//		v[a].push_back(b);
//		v[b].push_back(a);
//	}
//	for (int i = 1; i <= n; i++) {
//		cin >> a;
//		order.push(a);
//		bfs[a] = i;
//	}
//	for (int i = 1; i <= n; i++) {
//		sort(v[i].begin(), v[i].end(), comp);
//	}
//
//	if (order.front() != 1) {
//		cout << "0\n";
//		return 0;
//	}
//	else {
//		queue<int> q;
//		q.push(1);
//		order.pop();
//		while (!q.empty()) {
//			int temp = q.front();
//			q.pop();
//			for (auto it : v[temp]) {
//				if (it == order.front()) {
//					q.push(order.front());
//					order.pop();
//				}
//			}
//		}
//	}
//	if (order.empty()) cout << "1\n";
//	else cout << "0\n";
//}