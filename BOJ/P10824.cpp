#include <iostream>
#include <string>
using namespace std;

int main(void) {
	int n1 = 0;
	string a[4];
	while (n1 < 4) {
		cin >> a[n1++];
	}

	// 1000000
	unsigned long long n2 = stoull(a[0] + a[1]);
	unsigned long long n3 = stoull(a[2] + a[3]);


	cout << n2 + n3 << endl;
	
	return 0;
}