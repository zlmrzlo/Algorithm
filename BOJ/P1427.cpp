#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool descending(int left, int right) {
    return left > right;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    // 1. N�� �Է¹޴´�.
    int number;
    cin >> number;
    vector<int> numberSort(12);
    int count = 0;

    // 2. N�� �� �ڸ����� �ɰ���.
    while (number != 0) {
        numberSort.push_back(number % 10);
        number /= 10;
        count++;
    }

    // 3. �� �ڸ����� �����Ѵ�.
    sort(numberSort.begin(), numberSort.end(), descending);
    
    // 4. ���ĵ� ���� ����Ѵ�.
    for (int i = 0; i < count; i++) {
        cout << numberSort[i];
    }
    
    return 0;
}