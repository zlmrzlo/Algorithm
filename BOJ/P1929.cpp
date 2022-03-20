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

// �����佺�׳׽��� ü
// ��ó: https://donggoolosori.github.io/2020/10/16/eratos/
//#include <iostream>
//#include <cmath>
//using namespace std;
//
//int number = 120; // ���ϰ��� �ϴ� �Ҽ��� ����
//int primeNum[121];
//
//void primeNumberSieve() {
//    // primeNum �迭 �ʱ�ȭ
//    for (int i = 2; i <= number; i++) {
//        primeNum[i] = i;
//    }
//
//    for (int i = 2; i <= sqrt(number); i++) {
//        // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
//        if (primeNum[i] == 0)
//            continue;
//        // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
//        for (int j = i * i; j <= number; j += i)
//            primeNum[j] = 0;
//    }
//
//    // �Ҽ� ���
//    for (int i = 2; i <= number; i++) {
//        if (primeNum[i] != 0)
//            printf("%d\n", primeNum[i]);
//    }
//}
//int main() {
//    primeNumberSieve();
//}

// ios_base::sync_with_stdio(false); cout.tie(NULL); �̰� �ϰ� endl�� \n�� �ٲ㼭 �ذ�