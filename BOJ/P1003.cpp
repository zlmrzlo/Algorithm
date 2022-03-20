#include <iostream>
using namespace std;

int fiboZero[41], fiboOne[41];
int testCase;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> testCase;

    int number;
    fiboZero[0] = 1;
    fiboZero[1] = 0;
    
    fiboOne[0] = 0;
    fiboOne[1] = 1;

    for (int i = 2; i < 41; i++) {
        fiboZero[i] = fiboZero[i - 1] + fiboZero[i - 2];
        fiboOne[i] = fiboOne[i - 1] + fiboOne[i - 2];
    }

    while (testCase != 0) {
        cin >> number;
        if (number == 0) {
            cout << fiboZero[number] << ' ' << fiboOne[number] << '\n';
        }
        else if (number == 1) {
            cout << fiboZero[number] << ' ' << fiboOne[number] << '\n';
        }
        else {
            cout << fiboZero[number - 1] + fiboZero[number - 2] << ' '
                << fiboOne[number - 1] + fiboOne[number - 2] << '\n';
        }
        testCase--;
    }

	return 0;
}