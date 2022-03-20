#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, int>& left, const pair<int, int>& right) {
    if (left.second == right.second) {
        return left.first < right.first;
    }
    return left.second < right.second;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. 점의 총 개수를 입력받는다.
    int count;
    cin >> count;

    // 2. 점의 좌표를 하나씩 입력받는다.
    pair<int, int>* position = new pair<int, int>[count];
    for (int i = 0; i < count; i++) {
        cin >> position[i].first >> position[i].second;
    }
    
    // 3. x좌표 오름차순, 같을 때는 y좌표 오름차순으로 정렬
    sort(position, position + count, compare);

    // 4. 정렬된 좌표 출력
    for (int i = 0; i < count; i++) {
        cout << position[i].first << " " << position[i].second << '\n';
    }

    return 0;
}

// 참고: https://withhamit.tistory.com/195