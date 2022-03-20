#include <iostream>
using namespace std;

// 좌표 하나당 *(별) 하나를 출력하는 함수
void star(int i, int j, int num) {
    // i % 3 == 1 && j % 3 == 1
    // 에서 빈칸이 도출되는 반복 패턴이 발생
    // 이걸 재귀로 표현
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else {
        // 재귀 단계의 제일 최소 단위
        // 일종의 탈출 조건
        if (num / 3 == 0)
            cout << '*';
        else
            star(i, j, num / 3);
    }
}

int main() {
    int num;
    cin >> num;
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++)
            star(i, j, num);
        cout << '\n';
    }
}

// 참고: https://cryptosalamander.tistory.com/38