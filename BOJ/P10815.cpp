#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void Input() {
	int has_size = 0;
	cin >> has_size;
	vector<int> has_array(has_size, 0);
	for (int i = 0; i < has_size; i++) {
		cin >> has_array[i];
	}

	sort(has_array.begin(), has_array.end());

	int check_size = 0;
	cin >> check_size;
	vector<int> check_array(check_size, 0);
	vector<int> answer_array(check_size, 0);
	for (int i = 0; i < check_size; i++) {
		cin >> check_array[i];

		int left = 0;
		int right = has_size - 1;
		while (left <= right) {
			int mid = (left + right) / 2;

			if (has_array[mid] == check_array[i]) {
				answer_array[i]++;
				break;
			}
			else if (has_array[mid] < check_array[i]) {
				left = mid + 1;
			}
			else if (has_array[mid] > check_array[i]) {
				right = mid - 1;
			}
		}
	}

	for (int i = 0; i < check_size; i++) {
		cout << answer_array[i] << ' ';
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