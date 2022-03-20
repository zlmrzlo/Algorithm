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

    // 1. N과 M을 입력받는다.
    // N은 1부터 N까지를 의미
    // M은 중복 없이 M개 고르는 것을 의미
    cin >> N >> M;

    // 2. dfs 기반의 백트래킹을 실행한다.
    BackTracking(0);

    return 0;
}

// 참고 : https://cryptosalamander.tistory.com/54