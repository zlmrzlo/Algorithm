#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n1, n2, n3;
void Input() {
    cin >> n1 >> n2 >> n3;
}

void Solution() {
    int n4 = 1;
    while (1) {
        if ((n4 - n1) % 15 == 0 && (n4 - n2) % 28 == 0 && (n4 - n3) % 19 == 0) break;
        n4++;
    }
    cout << n4 << endl;
}

void Solve() {
}

int main(void) {
    ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);

    Input();
    Solution();

    return 0;
}