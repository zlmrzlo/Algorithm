#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. x��ǥ�� �� ������ �Է¹޴´�.
    int count;
    cin >> count;

    // 2. x��ǥ�� �Է¹޴´�.
    vector<int> compression(count);
    set<int> copy;
    for (int i = 0; i < count; i++) {
        cin >> compression[i];
    }

    // 3. �������� �����Ѵ�.
    for (int i = 0; i < count; i++) {
        copy.insert(compression[i]);
    }
    //set<int>::iterator iter = copy.begin();
    //for (; iter != copy.end(); iter++) {
    //    cout << *iter << endl;
    //}

    // 4. �������� ���ĵ� ������ ���ο� x��ǥ�� �ȴ�.
    vector<int> sortCopy(copy.size());
    set<int>::iterator iter;
    int i = 0;
    for (iter = copy.begin(); iter != copy.end(); iter++, i++) {
        sortCopy[i] = *iter;
    }

    // 5. ���ο� x��ǥ�� ����Ѵ�.
    // �ٷ� �Ʒ� for���� ��ȿ������ ���
    //for (int i = 0; i < count; i++) {
    //    for (int j = 0; j < pair.size(); j++) {
    //        if (pair[j].first == compression[i]) {
    //            cout << pair[j].second << " ";
    //        }
    //    }
    //}

    for (int i = 0; i < count; i++) {
        cout << lower_bound(sortCopy.begin(), sortCopy.end(), compression[i]) - sortCopy.begin() << " ";
    }

    return 0;
}

// ���� : https://www.acmicpc.net/source/39677864
// unique �Լ��� �̿��Ͽ� �ߺ��� �����ϴ� ������� Ǯ��
//#include <algorithm>
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main() {
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
//
//    int n;
//    cin >> n;
//    vector<int> v(n); //���� ����
//    // �Է�
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//    vector<int> cv(v); // ���� ���͸� �����Ͽ� �ߺ� �� ���� �����ϰ� ������ ���� �� ����.
//    sort(cv.begin(), cv.end()); //�������� ����
//    // �ߺ� ����
//    cv.erase(unique(cv.begin(), cv.end()), cv.end());
//    for (int i = 0; i < n; i++) {
//        // i��° ��Ұ��� ��ġ it
//        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
//        // it���� cv������ ���� �ּҰ��� ���� ���� ��
//        cout << it - cv.begin() << ' ';
//    }
//
//    return 0;
//}