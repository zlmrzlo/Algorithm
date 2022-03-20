#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. N�� �Է¹޴´�.
    int count;
    cin >> count;

    // 2. N���� ������ �Է¹޴´�.
    vector<int> container(count + 1);
    vector<int> counter(8001);
    int number;
    int sum = 0;
    for (int i = 1; i <= count; i++) {
        cin >> number;
        sum += number;
        container[i] = number + 4000;
        counter[container[i]]++;
    }

    //for (int i = 1; i <= count; i++) {
    //    cout << container[i] << endl;
    //}

    //for (int i = 0; i <= 8000; i++) {
    //    if (counter[i] != 0) {
    //        cout << counter[i] << endl;
    //    }
    //}

    // 3. �����Ѵ�.
    sort(container.begin(), container.end());

    // 4-3. �ֺ��� ����Ѵ�.
    int many = 0;
    int manyIndex;
    for (int i = 0; i < 8001; i++) {
        if (many < counter[i]) {
            many = counter[i];
            manyIndex = i;
        }
    }

    // �ֺ� ���� �� ���θ� Ȯ���Ѵ�.
    bool manySecond = false;
    for (int i = 0; i < 8001; i++) {
        if (many == counter[i]) {
            if (manySecond == true) {
                //cout << i << endl;
                manyIndex = i;
                many = counter[i];
                break;
            }
            manySecond = true;
        }
    }

    // 4-4. ������ ����Ѵ�.
    int max = 0;
    int min = 8000;
    for (int i = 1; i <= count; i++) {
        if (max < container[i]) {
            max = container[i];
        }
        if (min > container[i]) {
            min = container[i];
        }
    }

    // 4-1, 4-2. �����հ� �߾Ӱ��� ����Ѵ�.
    cout << floor((double)sum / count + 0.5) << endl;
    cout << container[count / 2 + 1] - 4000<< endl;
    cout << manyIndex - 4000 << endl;
    cout << max - min << endl;

    return 0;
}