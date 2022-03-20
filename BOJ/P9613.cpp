#include <iostream>
#include <vector>
using namespace std;

int GCD(int n1, int n2) {
	int c = n1 % n2;
	while (c != 0) {
		n1 = n2;
		n2 = c;
		c = n1 % n2;
	}

	return n2;
}

int main(void) {

	int t1;
	cin >> t1;
	while (t1--) {
		int n1;
		cin >> n1;

		vector<int> v1(n1);
		for (int i = 0; i < v1.size(); i++) {
			cin >> v1[i];
		}

		unsigned long long sum = 0;
		for (int i = 0; i < v1.size(); i++) {
			for (int j = i + 1; j < v1.size(); j++) {
				sum += GCD(v1[i], v1[j]);
			}
		}
		cout << sum << endl;
	}
	return 0;
}