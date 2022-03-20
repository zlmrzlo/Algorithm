#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Compare {
    bool operator() (const string& a, const string& b) const {
        if (a.size() == b.size())
            return a < b;
        else
            return a.size() < b.size();
    }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. 단어의 총 개수를 입력받는다.
    int count;
    cin >> count;

    // 2. 단어를 하나씩 입력받는다.
    set<string, Compare> voca;

    //    set이라서 중복은 자동으로 제거된다.
    //    set template 인자에 비교 연산 함수를 넣어주면
    //    그것을 기준으로 자동 정렬이 진행된다.
    for (int i = 0; i < count; i++) {
        string temporary;
        cin >> temporary;
        voca.insert(temporary);
    }

    // 3. 정렬된 단어 출력
    set<string>::iterator iterator;
    for (iterator = voca.begin(); iterator != voca.end(); iterator++) {
        cout << *iterator << '\n';
    }

    return 0;
}

// 참고: https://chanhuiseok.github.io/posts/algo-46/