#include <iostream>
using namespace std;

int main() {
	double fixedCost, variableCost, productCost;

	cin >> fixedCost >> variableCost >> productCost;

	// fixedCost + variableCost * count <= productCost * count
	// fixedCost <= (productCost - variableCost) * cost
	// fixedCost / (productCost - variableCost) <= cost
	int count = (int)(fixedCost / (productCost - variableCost) + 1);

	if (count <= 0) {
		cout << -1 << endl;
	}
	else {
		cout << count << endl;
	}

	return 0;
}