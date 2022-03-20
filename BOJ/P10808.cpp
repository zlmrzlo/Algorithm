#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void) {
	string s1;
	cin >> s1;

	vector<int> v1(26);
	for (int i = 0; i < s1.size(); i++) {
		v1[s1[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		cout << v1[i] << ' ';
	}
	
	return 0;
}