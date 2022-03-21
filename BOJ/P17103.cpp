#include <bits/stdc++.h>
using namespace std;
int number = 1000000; // ���ϰ��� �ϴ� �Ҽ��� ����
int primeNumber[1000001];

void PrimeNumberSieve() {
    // primeNum �迭 �ʱ�ȭ
    for (int i = 2; i <= number; i++) {
        primeNumber[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        // primeNum[i] �� 0�̸� �̹� �Ҽ��� �ƴϹǷ� continue
        if (primeNumber[i] == 0)
            continue;
        // i*k (k<i) ������ ���� �̹� �˻������Ƿ� j�� i*i ���� �˻����ش�.
        for (int j = i * i; j <= number; j += i)
            primeNumber[j] = 0;
    }

    //// �Ҽ� ���
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