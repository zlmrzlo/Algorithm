#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<int> number(9);
vector<bool> visited(9);

void BackTracking(int count) {
    if (count == M) {
        for (int i = 0; i < M; i++) {
            cout << number[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            visited[i] = true;
            number[count] = i;
            BackTracking(count + 1);
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. N�� M�� �Է¹޴´�.
    // N�� 1���� N������ �ǹ�
    // M�� �ߺ� ���� M�� ���� ���� �ǹ�
    cin >> N >> M;

    // 2. dfs ����� ��Ʈ��ŷ�� �����Ѵ�.
    BackTracking(0);

    return 0;
}

// ���� : https://cryptosalamander.tistory.com/54