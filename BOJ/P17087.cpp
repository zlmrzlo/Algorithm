#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main(void) {
	// ������ ��(a1)�� ������ ���� ��ġ(a2)�� �Է¹���
	int n1, n2;
	cin >> n1 >> n2;

	// �� ������ �� ��ġ�� ������
	vector<int> v1(n1);
	vector<int> v2(n1);
	int i1 = 0;
	while (n1--) {
		cin >> v1[i1];
		v2[i1] = abs(n2 - v1[i1]);
		i1++;
	}

	sort(v2.begin(), v2.end());

	cout << v2[0] << endl;

	return 0;
}