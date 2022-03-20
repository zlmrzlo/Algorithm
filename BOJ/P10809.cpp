#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string s1;
	cin >> s1;

	vector<int> v1(26);

	int index;
	if (v1[s1[0] - 'a'] == 0) {
		v1[s1[0] - 'a'] = s1.find_first_of(s1[0]);
		index = s1[0] - 'a';
	}

	for (int i = 1; i < s1.size(); i++) {
		if (v1[s1[i] - 'a'] == 0) {
			v1[s1[i] - 'a'] = s1.find_first_of(s1[i]);
			//cout << s1.find_first_of(s1[i]) << ' ';
		}
	}

	for (int i = 0; i < v1.size(); i++) {
		if (i != index && v1[i] == 0) {
			v1[i] = -1;
		}

		cout << v1[i] << ' ';
	}

	return 0;
}