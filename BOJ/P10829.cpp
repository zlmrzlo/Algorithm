#include <iostream>
#include <vector>

using namespace std;
typedef unsigned long long ull;
vector<ull> vectorBinary;
ull number;

void PrintBinary() {
	for (int i = vectorBinary.size() - 1; i >= 0; i--) {
		cout << vectorBinary[i];
	}
}

void ToBinary(ull number) {
	if (number == 0) {
		PrintBinary();
		return;
	}

	vectorBinary.push_back(number % 2);
	ToBinary(number /= 2);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

	cin >> number;
	ToBinary(number);

	return 0;
}