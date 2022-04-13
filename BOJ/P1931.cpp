#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5+1

int meeting_count;
int result = 1;
vector<pair<int, int>> meeting;

void Input() {
	cin >> meeting_count;

	int start, end;
	while (meeting_count--) {
		cin >> start >> end;
		meeting.push_back({ end, start });
	}

	sort(meeting.begin(), meeting.end());

	int end_time = meeting[0].first;
	for (int i = 1; i < meeting.size(); i++) {
		if (end_time <= meeting[i].second) {
			result++;
			end_time = meeting[i].first;
		}
	}

	cout << result << endl;
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}