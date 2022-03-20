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

//�������� �ϳ��� ž�� Ǯ�� ����� ������ �ȴ�.
//1�� ��뿡 �ִ� ������ 3�� ���� ��� �ű�� ���� ����� ������ ������ ������ ������.
//���� n - 1���� ������ 3�� ��븦 ���� 2�� ���� �ű��,
//1�� ��뿡 �ִ� ���� ū ũ���� ������ 3�� ���� �ű� ��,
//2�� ��뿡 �ִ� n - 1���� ������ 1�� ��븦 ���� 3�� ���� �÷� ���� �����̴�.
//�̸� �״�� �˰���ȭ�ϸ� ���� Ǯ �� �ִ�.
//����, �ּ� Ƚ���� ��쿡�� �ϳ��� ž���� ������ ������ N�϶�,
//2 ^ N - 1 �� Ƚ���� �ּ� Ƚ���̴�.
// ����: https://cryptosalamander.tistory.com/39