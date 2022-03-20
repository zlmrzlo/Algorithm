#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s1;
	getline(cin, s1);

	for (int i = 0; i < s1.size(); i++) {
		int n1 = 0;
		if (s1[i] >= 'A' && s1[i] <= 'Z') {
			n1 = s1[i] + 13;
			if (n1 > (int)'Z') {
				s1[i] -= 13;
			}
			else {
				s1[i] += 13;
			}
		}
		if (s1[i] >= 'a' && s1[i] <= 'z') {
			n1 = s1[i] + 13;
			if (n1 > (int)'z') {
				s1[i] -= 13;
			}
			else {
				s1[i] += 13;
			}
		}
		cout << s1[i];
	}

	return 0;
}