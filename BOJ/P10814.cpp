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

    // 1. ������ �� ������ �Է¹޴´�.
    int count;
    cin >> count;

    // 2. �ܾ �ϳ��� �Է¹޴´�.
    pair<int, string>* person = new pair<int, string>[count];

    for (int i = 0; i < count; i++) {
        cin >> person[i].first >> person[i].second;
    }

    // 3. ���� ���ķ� �����Ѵ�.
    stable_sort(person, person + count, Compare);

    // 4. ���ĵ� �ܾ� ���
    for (int i = 0; i < count; i++) {
        cout << person[i].first << " " << person[i].second << '\n';
    }

    return 0;
}