#include <iostream>
using namespace std;

// ��ǥ �ϳ��� *(��) �ϳ��� ����ϴ� �Լ�
void star(int i, int j, int num) {
    // i % 3 == 1 && j % 3 == 1
    // ���� ��ĭ�� ����Ǵ� �ݺ� ������ �߻�
    // �̰� ��ͷ� ǥ��
    if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
        cout << ' ';
    }
    else {
        // ��� �ܰ��� ���� �ּ� ����
        // ������ Ż�� ����
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

// ����: https://cryptosalamander.tistory.com/38