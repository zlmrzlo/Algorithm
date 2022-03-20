#include <iostream>
#include <vector>
using namespace std;


int main() {
	int min, max;
	cin >> min >> max;

	vector<pair<int, int>> primeVector(10001);
	for (int i = 1; i < primeVector.size(); i++) {
		primeVector[i].first = i;
	}

	int divide = 1;
	while (divide < 10001) {
		if (primeVector[divide].second <= 2) {
			for (int i = 1; i < primeVector.size(); i++) {
				if (primeVector[i].first % divide == 0 && primeVector[i].second <= 2) {
					if (primeVector[i].first == 1 || primeVector[i].first == i) {
						primeVector[i].second++;
					}
					else {
						primeVector[i].second = 3;
					}
				}
			}
		}
		divide++;
	}

	int targetIndex = 0;
	int sum = 0;
	vector<int> target(10001);
	for (int i = 1; i < primeVector.size(); i++) {
		if (primeVector[i].second == 2) {
			if (primeVector[i].first >= min && primeVector[i].first <= max) {
				//cout << primeVector[i].first << " ";
				target[targetIndex++] = primeVector[i].first;
				sum += primeVector[i].first;
			}
		}
	}

	if (targetIndex != 0) {
		cout << sum << endl << target[0] << endl;
	}
	else {
		cout << -1 << endl;
	}

	return 0;
}


// 다른 사람 빠른 거 
// 제출번호: 39452901	
// 아이디: ehdgk06021
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//bool isPrimeNum(int n);
//
//int main() {
//	int m, n, sum = 0, firstPrime;
//
//	cin >> m;
//	cin >> n;
//
//	for (int i = m; i <= n; i++) {
//		if (isPrimeNum(i)) {
//			if (sum == 0) {
//				firstPrime = i;
//			}
//			sum += i;
//		}
//	}
//
//	if (sum != 0) {
//		cout << sum << endl;
//		cout << firstPrime << endl;
//	}
//	else {
//		cout << -1;
//	}
//
//	return 0;
//}
//
//bool isPrimeNum(int n) {
//	if (n < 2) {
//		return false;
//	}
//	if (n == 2) {
//		return true;
//	}
//	for (int i = 2; i < sqrt(n) + 1; i++) {
//		if (n % i == 0) {
//			return false;
//		}
//	}
//
//	return true;
//}