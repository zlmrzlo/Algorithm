#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
	string s1;
	cin >> s1;

	vector<string> v1(s1.size());
	for (int i = 0; i < s1.size(); i++) {
		for (int j = i; j < s1.size(); j++) {
			v1[i] += s1[j];
		}
	}

	sort(v1.begin(), v1.end());

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << '\n';
	}
	return 0;
}