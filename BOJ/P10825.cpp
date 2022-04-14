#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

struct Student {
	string name;
	int kor;
	int eng;
	int math;
}student;

bool Compare_Student(const Student left, const Student right) {
	if (left.kor > right.kor) {
		return true;
	}
	else if (left.kor == right.kor) {
		if (left.eng < right.eng) {
			return true;
		}
		else if (left.eng == right.eng) {
			if (left.math > right.math) {
				return true;
			}
			else if (left.math == right.math) {
				if (left.name < right.name) {
					return true;
				}
			}
		}
	}
	return false;
}

void Input() {
	int human_count;
	cin >> human_count;
	Student* student = new Student[human_count];
	for (int i = 0; i < human_count; i++) {
		cin >> student[i].name >> student[i].kor >>
			student[i].eng >> student[i].math;
	}

	sort(student, student + human_count, Compare_Student);

	for (int i = 0; i < human_count; i++) {
		cout << student[i].name << endl;
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