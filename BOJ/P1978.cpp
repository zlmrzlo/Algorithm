#include <iostream>
#include <vector>
using namespace std;


int main() {
	int totalNumber;
	cin >> totalNumber;
	vector<int> checkPrime(101);

	int index = 0;
	while (totalNumber > 0) {
		cin >> checkPrime[index++];
		totalNumber--;
	}

	//for (int i = 0; i < index; i++) {
	//	cout << checkPrime[i];
	//}
	//cout << endl;

	vector<pair<int ,int>> primeVector(1001);
	for (int i = 1; i < primeVector.size(); i++) {
		primeVector[i].first = i;
		//cout << primeVector[i].first << endl;
	}

	int divide = 1;
	while (divide < 1001) {
		for (int i = 1; i < primeVector.size(); i++) {
			if (primeVector[i].first % divide == 0) {
				primeVector[i].second++;
			}
		}

		divide++;
	}

	//for (int i = 1; i < primeVector.size(); i++) {
	//	if (primeVector[i].second <= 2) {
	//		cout << primeVector[i].first << endl;
	//	}
	//}

	int count = 0;
	for (int i = 0; i < index; i++) {
		if (primeVector[checkPrime[i]].second == 2) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}