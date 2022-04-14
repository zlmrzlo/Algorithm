#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void Input() {
    int N;
    cin >> N;
    vector<pair<int, int>> bubble(N + 1);
    int temp;
    for (int i = 1; i <= N; i++) {
        cin >> bubble[i].first;
        bubble[i].second = i;
    }

    sort(bubble.begin(), bubble.end());

    int max_number = 0;
    for (int i = 1; i < bubble.size(); i++) {
        max_number = max(max_number, bubble[i].second - i + 1);
    }

    cout << max_number << endl;
}


void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}