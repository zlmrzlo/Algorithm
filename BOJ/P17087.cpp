#include <iostream>
#include <vector>
using namespace std;

int GCD(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return GCD(n2, n1 % n2);
	}
}

int main(void) {
	int n1, n2;
	cin >> n1 >> n2;

	int n3;
	vector<int> v2(n1);
	int i1 = 0;
	while (n1--) {
		cin >> n3;
		v2[i1++] = abs(n2 - n3);
	}

	int a1 = v2[0];
	for (int i = 1; i < v2.size(); i++) {
		a1 = GCD(a1, v2[i]);
	}

	cout << a1 << endl;

	return 0;
}