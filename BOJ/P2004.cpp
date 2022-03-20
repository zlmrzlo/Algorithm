#include <iostream>
using namespace std;

unsigned long long func(unsigned long long n, unsigned long long r) {
    unsigned long long n1 = 0;

    for (unsigned long long i = r; i <= n; i *= r) {
        n1 += n / i;
    }

    return n1;
}

int main() {
    unsigned long long n1, n2, n3;
    cin >> n1 >> n2;
    n3 = n1 - n2;

    unsigned long long two = func(n1, 2) - func(n2, 2) - func(n3, 2);
    unsigned long long five = func(n1, 5) - func(n2, 5) - func(n3, 5);

    cout << min(two, five);
    return 0;
}

// Âü°í: https://j3sung.tistory.com/235