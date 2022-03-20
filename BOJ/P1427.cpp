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
    
    // 1. N을 입력받는다.
    int number;
    cin >> number;
    vector<int> numberSort(12);
    int count = 0;

    // 2. N을 각 자리수로 쪼갠다.
    while (number != 0) {
        numberSort.push_back(number % 10);
        number /= 10;
        count++;
    }

    // 3. 각 자리수를 정렬한다.
    sort(numberSort.begin(), numberSort.end(), descending);
    
    // 4. 정렬된 것을 출력한다.
    for (int i = 0; i < count; i++) {
        cout << numberSort[i];
    }
    
    return 0;
}