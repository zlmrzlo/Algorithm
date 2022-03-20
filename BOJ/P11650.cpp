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

    // 1. ���� �� ������ �Է¹޴´�.
    int count;
    cin >> count;

    // 2. ���� ��ǥ�� �ϳ��� �Է¹޴´�.
    pair<int, int>* position = new pair<int, int>[count];
    for (int i = 0; i < count; i++) {
        cin >> position[i].first >> position[i].second;
    }
    
    // 3. x��ǥ ��������, ���� ���� y��ǥ ������������ ����
    sort(position, position + count, compare);

    // 4. ���ĵ� ��ǥ ���
    for (int i = 0; i < count; i++) {
        cout << position[i].first << " " << position[i].second << '\n';
    }

    return 0;
}

// ����: https://withhamit.tistory.com/195