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

    // 1. �ܾ��� �� ������ �Է¹޴´�.
    int count;
    cin >> count;

    // 2. �ܾ �ϳ��� �Է¹޴´�.
    set<string, Compare> voca;

    //    set�̶� �ߺ��� �ڵ����� ���ŵȴ�.
    //    set template ���ڿ� �� ���� �Լ��� �־��ָ�
    //    �װ��� �������� �ڵ� ������ ����ȴ�.
    for (int i = 0; i < count; i++) {
        string temporary;
        cin >> temporary;
        voca.insert(temporary);
    }

    // 3. ���ĵ� �ܾ� ���
    set<string>::iterator iterator;
    for (iterator = voca.begin(); iterator != voca.end(); iterator++) {
        cout << *iterator << '\n';
    }

    return 0;
}

// ����: https://chanhuiseok.github.io/posts/algo-46/