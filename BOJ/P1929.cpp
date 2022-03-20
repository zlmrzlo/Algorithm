#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 123456;

int main() {
	ios_base::sync_with_stdio(false); cout.tie(NULL);
	int min, max;
	cin >> min >> max;

	bool prime[SIZE];

	memset(prime, true, SIZE * sizeof(bool));
	prime[0] = false;
	prime[1] = false;

	for (int i = 2; i <= sqrt(SIZE); i++) {
		if (prime[i]) {
			for (int j = i * i; j <= SIZE - 1; j += i) {
				prime[j] = false;
			}
		}
	}

	for (int i = min; i <= max; i++) {
		//cout << prime[i] << endl;
		if (prime[i]) {
			cout << i << '\n';
		}
	}

	return 0;
}

// 에라토스테네스의 체
// 출처: https://donggoolosori.github.io/2020/10/16/eratos/
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int number = 120; // 구하고자 하는 소수의 범위
//int primeNum[121];
//
//void primeNumberSieve() {
//    // primeNum 배열 초기화
//    for (int i = 2; i <= number; i++) {
//        primeNum[i] = i;
//    }
//
//    for (int i = 2; i <= sqrt(number); i++) {
//        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
//        if (primeNum[i] == 0)
//            continue;
//        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
//        for (int j = i * i; j <= number; j += i)
//            primeNum[j] = 0;
//    }
//
//    // 소수 출력
//    for (int i = 2; i <= number; i++) {
//        if (primeNum[i] != 0)
//            printf("%d\n", primeNum[i]);
//    }
//}
//int main() {
//    primeNumberSieve();
//}

// ios_base::sync_with_stdio(false); cout.tie(NULL); 이거 하고 endl을 \n로 바꿔서 해결