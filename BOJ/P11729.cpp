#include <iostream>
using namespace std;

void hanoi(int count, int start, int to, int bypass) {
    if (count == 1) {
        cout << start << " " << to << '\n';
    }
    else {
        hanoi(count - 1, start, bypass, to);
        cout << start << " " << to << '\n';
        hanoi(count - 1, bypass, to, start);
    }
}

int main() {
    int count;
    cin >> count;
    cout << (1 << count) - 1 << '\n';
    hanoi(count, 1, 3, 2);
    return 0;
}

//정석적인 하노이 탑의 풀이 방법을 따르면 된다.
//1번 장대에 있는 원판을 3번 장대로 모두 옮기기 위한 방법은 무조건 동일한 절차를 따른다.
//먼저 n - 1개의 원판을 3번 장대를 거쳐 2번 장대로 옮기고,
//1번 장대에 있는 가장 큰 크기의 원판을 3번 장대로 옮긴 후,
//2번 장대에 있는 n - 1개의 원판을 1번 장대를 거쳐 3번 장대로 올려 놓는 과정이다.
//이를 그대로 알고리즘화하면 쉽게 풀 수 있다.
//또한, 최소 횟수의 경우에는 하노이 탑에서 원판의 개수가 N일때,
//2 ^ N - 1 의 횟수가 최소 횟수이다.
// 참고: https://cryptosalamander.tistory.com/39