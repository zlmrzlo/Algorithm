#include <iostream>

using namespace std;

int main() {
    int ans = 0;

    int n;
    cin >> n;
    // 1 2 3 4 5 6 7 8 9 10
    // 11 12 13 14 15 16 17 18 19 20
    // 21 22 23 24 25
    for (int i = 5; i <= n; i *= 5) {
        ans += n / i;
        cout << ans << endl;
    }

    cout << ans << '\n';
    return 0;
}

// 참고: https://luv-n-interest.tistory.com/957
// 참고: https://www.crocus.co.kr/391