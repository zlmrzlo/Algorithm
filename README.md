# Algorithm
알고리즘 공부 흔적
- 새롭게 알게 된 지식을 추가함
- 반복되어 사용되는 부분을 따로 작성함
- 공부과정에서 실수한 부분 작성함
- 공부과정에서 놓친 부분 작성함

# 최소공배수
- 재귀 방식

```cpp
int GCD(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return GCD(n2, n1 % n2);
	}
}
```

- 반복 방식

```cpp
int GCD(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
```

#에라토스테네스의 체
```cpp
#include <iostream>
#include <cmath>
using namespace std;

int number = 120; // 구하고자 하는 소수의 범위
int primeNum[121];

void primeNumberSieve()
{
    // primeNum 배열 초기화
    for (int i = 2; i <= number; i++)
    {
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(number); i++)
    {
        // primeNum[i] 가 0이면 이미 소수가 아니므로 continue
        if (primeNum[i] == 0)
            continue;
        // i*k (k<i) 까지의 수는 이미 검사했으므로 j는 i*i 부터 검사해준다.
        for (int j = i * i; j <= number; j += i)
            primeNum[j] = 0;
    }

    // 소수 출력
    for (int i = 2; i <= number; i++)
    {
        if (primeNum[i] != 0)
            printf("%d\n", primeNum[i]);
    }
}
int main()
{
    primeNumberSieve();
}
```
