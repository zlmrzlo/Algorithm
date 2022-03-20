#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
	string s1;

	while (getline(cin, s1)) {
		vector<int> v1(4);
		for (int i = 0; i < s1.size(); i++) {
			if (s1[i] >= 'a' && s1[i] <= 'z') {
				v1[0]++;
			}
			else if (s1[i] >= 'A' && s1[i] <= 'Z') {
				v1[1]++;
			}
			else if (s1[i] >= '0' && s1[i] <= '9') {
				v1[2]++;
			}
			else if (s1[i] == ' ') {
				v1[3]++;
			}
		}

		for (int i = 0; i < v1.size(); i++) {
			cout << v1[i] << ' ';
		}
		cout << '\n';
	}

	return 0;
}