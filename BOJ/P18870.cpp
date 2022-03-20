#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    // 1. x좌표의 총 개수를 입력받는다.
    int count;
    cin >> count;

    // 2. x좌표를 입력받는다.
    vector<int> compression(count);
    set<int> copy;
    for (int i = 0; i < count; i++) {
        cin >> compression[i];
    }

    // 3. 오름차순 정렬한다.
    for (int i = 0; i < count; i++) {
        copy.insert(compression[i]);
    }
    //set<int>::iterator iter = copy.begin();
    //for (; iter != copy.end(); iter++) {
    //    cout << *iter << endl;
    //}

    // 4. 오름차순 정렬된 순서가 새로운 x좌표가 된다.
    vector<int> sortCopy(copy.size());
    set<int>::iterator iter;
    int i = 0;
    for (iter = copy.begin(); iter != copy.end(); iter++, i++) {
        sortCopy[i] = *iter;
    }

    // 5. 새로운 x좌표를 출력한다.
    // 바로 아래 for문은 비효율적인 방식
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

// 참고 : https://www.acmicpc.net/source/39677864
// unique 함수를 이용하여 중복을 제거하는 방식으로 풀이
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
//    vector<int> v(n); //원본 벡터
//    // 입력
//    for (int i = 0; i < n; i++) {
//        cin >> v[i];
//    }
//    vector<int> cv(v); // 원본 벡터를 복사하여 중복 된 수를 제거하고 정렬을 시행 할 벡터.
//    sort(cv.begin(), cv.end()); //오름차순 정렬
//    // 중복 제거
//    cv.erase(unique(cv.begin(), cv.end()), cv.end());
//    for (int i = 0; i < n; i++) {
//        // i번째 요소값의 위치 it
//        auto it = lower_bound(cv.begin(), cv.end(), v[i]);
//        // it에서 cv벡터의 시작 주소값을 빼준 값이 답
//        cout << it - cv.begin() << ' ';
//    }
//
//    return 0;
//}