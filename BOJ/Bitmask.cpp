#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

vector<int> numbers;
int target;
int numbers_size;
int answer;

// input data : 2 4 4 1 2 1

void Input() {
    cin >> target;
    cin >> numbers_size;

    numbers.resize(numbers_size);

    for (int i = 0; i < numbers.size(); i++) {
        cin >> numbers[i];
    }
}

void Solution(void) {
    int bitmask_size = 1 << numbers.size();

    for (int i = 1; i < bitmask_size; i++) {
        int temp = 0;

        for (int j = 0; j < numbers.size(); j++) {
            if (i & (1 << j)) {
                temp += numbers[j];
            }
            else {
                temp -= numbers[j];
            }
        }

        if (temp == target) {
            answer++;
        }
    }

    cout << answer << endl;
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	Input();
	Solution();

	return 0;
}