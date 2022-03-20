#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int edge1, edge2, edge3;
	vector<string> answer;

	bool loop = true;
	while (loop) {
		cin >> edge1 >> edge2 >> edge3;
		if (edge1 == 0 && edge2 == 0 && edge3 == 0) {
			loop = false;
		}
		else {
			if (edge3 > edge1 && edge3 > edge2) {
				if (pow(edge3, 2) == pow(edge1, 2) + pow(edge2, 2)) {
					cout << "right" << endl;
				}
				else {
					cout << "wrong" << endl;
				}
			}
			else if (edge2 > edge1 && edge2 > edge3) {
				if (pow(edge2, 2) == pow(edge1, 2) + pow(edge3, 2)) {
					cout << "right" << endl;
				}
				else {
					cout << "wrong" << endl;
				}
			}
			if (edge1 > edge3 && edge1 > edge2) {
				if (pow(edge1, 2) == pow(edge3, 2) + pow(edge2, 2)) {
					cout << "right" << endl;
				}
				else {
					cout << "wrong" << endl;
				}
			}
		}
	}
	return 0;
}