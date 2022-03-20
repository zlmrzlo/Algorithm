#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

bool Compare(const pair<int, string> left, const pair<int, string> right) {
    return left.first < right.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. 정보의 총 개수를 입력받는다.
    int count;
    cin >> count;

    // 2. 단어를 하나씩 입력받는다.
    pair<int, string>* person = new pair<int, string>[count];

    for (int i = 0; i < count; i++) {
        cin >> person[i].first >> person[i].second;
    }

    // 3. 안정 정렬로 실행한다.
    stable_sort(person, person + count, Compare);

    // 4. 정렬된 단어 출력
    for (int i = 0; i < count; i++) {
        cout << person[i].first << " " << person[i].second << '\n';
    }

    return 0;
}