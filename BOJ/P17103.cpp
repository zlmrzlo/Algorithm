#include <bits/stdc++.h>
using namespace std;
int number = 1000000; // 구하고자 하는 소수의 범위
int primeNumber[1000001];

void PrimeNumberSieve() {
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++) {
        primeNumber[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNumber[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNumber[j] = 0;
    }

    //// 소수 출력
    //for (int i = 2; i <= number; i++) {
    //    if (primeNum[i] != 0)
    //        printf("%d\n", primeNum[i]);
    //}
}

void Solution() {
    PrimeNumberSieve();
    int n1;
    cin >> n1;
    while (n1--) {
        int c1 = 0;
        int n2;
        cin >> n2;
        int t1 = n2;
        for (int i = 2; i <= n2 / 2; i++) {
            if (primeNumber[i] != 0 && primeNumber[t1 - i] != 0) {
                c1++;
            }
        }
        cout << c1 << endl;
    }
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}