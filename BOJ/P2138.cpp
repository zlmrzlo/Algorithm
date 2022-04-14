#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX (int)1e5 + 1

int bulb_size, result = MAX;
string start, target, temp;

void Light(int index) {
	if (index > 0) {
		temp[index - 1] == '0' ? temp[index - 1] = '1' :
			temp[index - 1] = '0';
	}
	temp[index] == '0' ? temp[index] = '1' :
		temp[index] = '0';
	if (index < bulb_size - 1) {
		temp[index + 1] == '0' ? temp[index + 1] = '1' :
			temp[index + 1] = '0';
	}
}

void First_Bulb(bool on_off) {
	temp = start;
	int bulb_count = 0;
	
	if (on_off) {
		Light(0);
		bulb_count++;
	}

	for (int i = 1; i < bulb_size; i++) {
		if (temp[i - 1] != target[i - 1]) {
			Light(i);
			bulb_count++;
		}
	}
	if (temp == target) {
		result = min(result, bulb_count);
	}
}

void Input() {
	cin >> bulb_size >> start >> target;
}

void Solution(void) {
	First_Bulb(true);
	First_Bulb(false);
	if (result != MAX) {
		cout << result << endl;
	}
	else {
		cout << -1 << endl;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), std::cout.tie(NULL);
	Input();
	Solution();
	return 0;
}