#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double radius;
	cin >> radius;
	cout.precision(6);
	cout << fixed;
	cout << radius * radius * M_PI << endl;
	cout << 2 * radius * radius;

	return 0;
}