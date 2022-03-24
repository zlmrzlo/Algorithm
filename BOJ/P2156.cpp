#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define MAX 10001

int a1[MAX];
int a2[MAX][2];
void Solution(void) {
	int n1;
	cin >> n1;

	int i1 = 1;
	while (i1 <= n1) {
		cin >> a1[i1++];
	}

	a2[1][0] = 0;
	a2[1][1] = a1[1];
	for (int i = 2; i <= n1; i++) {
		a2[i][0] = max(a2[i - 1][0], a2[i - 1][1]);
		a2[i][1] = max(a1[i-1] + a2[i-2][0] + a1[i], a2[i-1][0] + a1[i]);
	}

	cout << max(a2[n1][0], a2[n1][1]) << endl;
	

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Solution();
	return 0;
}