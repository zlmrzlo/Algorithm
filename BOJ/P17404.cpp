#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 1001
#define LIMIT MAX * MAX + 1

int a1[MAX][3];
int a2[MAX][3];
void Solution(void) {
    int n1;
    cin >> n1;

    for (int i = 1; i <= n1; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a1[i][j];
        }
    }

    int n2 = LIMIT;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i == j) {
                a2[1][j] = a1[1][j];
            }
            else {
                a2[1][j] = LIMIT;
            }
        }

        for (int i = 2; i <= n1; i++) {
            a2[i][0] = min(a2[i - 1][1], a2[i - 1][2]) + a1[i][0];
            a2[i][1] = min(a2[i - 1][0], a2[i - 1][2]) + a1[i][1];
            a2[i][2] = min(a2[i - 1][0], a2[i - 1][1]) + a1[i][2];
        }

        for (int j = 0; j < 3; j++) {
            if (i != j) {
                n2 = min(n2, a2[n1][j]);
            }
        }
    }

    cout << n2 << endl;
}

int main(void) {
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    Solution();
    return 0;
}

// Âü°í: https://tjdahr25.tistory.com/16