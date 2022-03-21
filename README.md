# Algorithm
알고리즘 공부 흔적
- 새롭게 알게 된 지식을 추가함
- 반복되어 사용되는 부분을 따로 작성함
- 공부과정에서 실수한 부분 작성함
- 공부과정에서 놓친 부분 작성함

# 최소공배수
- 재귀 방식

'''cpp
int GCD(int n1, int n2) {
	if (n2 == 0) {
		return n1;
	}
	else {
		return GCD(n2, n1 % n2);
	}
}
'''

- 반복 방식

'''cpp
int GCD(int a, int b) {
	int c = a % b;
	while (c != 0) {
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}
'''
