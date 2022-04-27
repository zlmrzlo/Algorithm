#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int arr[10];
int arr2[10];

void Merge(int left, int right) {
	int mid = (left + right) / 2;

	int leftSide = left;
	int rightSide = mid + 1;
	int curPos = left;
	while (leftSide <= mid && rightSide <= right) {
		if (arr[leftSide] <= arr[rightSide]) {
			arr2[curPos++] = arr[leftSide++];
		}
		else {
			arr2[curPos++] = arr[rightSide++];
		}
	}

	int temp = leftSide > mid ? rightSide : leftSide;

	while (curPos <= right) {
		arr2[curPos++] = arr[temp++];
	}

	for (int i = left; i <= right; i++) {
		arr[i] = arr2[i];
	}
}

void Divide(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		Divide(left, mid);
		Divide(mid + 1, right);
		Merge(left, right);
	}

}

void Input() {
	for (int i = 0; i < 10; i++) {
		cin >> arr[i];
	}

	Divide(0, 9);

	for (int i = 0; i < 10; i++) {
		cout << arr2[i] << " ";
	}
}

void Solution(void) {

}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	Input();
	Solution();
	return 0;
}