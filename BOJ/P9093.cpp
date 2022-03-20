#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(void) {
	int testcase;
	cin >> testcase;
	cin.ignore();

	stack<char> stack;
	while (testcase--) {
		string line;
		getline(cin, line);
		line += "\n";
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ' || line[i] == '\n') {
				while (!stack.empty()) {
					cout << stack.top();
					stack.pop();
				}
				cout << line[i];
			}
			else {
				stack.push(line[i]);
			}
		}
	}

	return 0;
}



// 스택 자료구조를 사용하지 않은 풀이
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//
//// 1. 문장이 주어졌을 때, 단어를 모두 뒤집어서 출력
//// 2. 모든 단어는 알파벳으로 이루어져 있다.
//
//// 한 문장을 읽어온다.
//// 한 문장을 단어로 파싱한다.
//// 파싱된 단어를 모두 뒤집는다.
//
//int main(void) {
//	int testcase;
//	cin >> testcase;
//	string line;
//	cin.ignore();    
//    
//    int previous = 0;
//    int current = 0;
//    vector<string> x;
//    x.clear();
//
//	for (int i = 0; i < testcase; i++) {
//		getline(cin, line);
//		//cout << line << '\n';
//        
//        current = line.find(' ');
//        //find는 찾을게 없으면 npos를 리턴함
//        while (current != string::npos) {
//            string substring = line.substr(previous, current - previous);
//            x.push_back(substring);
//            previous = current + 1;
//            current = line.find(' ', previous);
//        }
//        x.push_back(line.substr(previous, current - previous));
//        previous = 0;
//        current = 0; 
//        x.push_back("\n");
//	}
//
//    for (int i = 0; i < x.size(); i++) {
//        //cout << x[i].size() << endl;
//        for (int j = 0; j < x[i].size() / 2; j++) {
//            swap(x[i][j], x[i][x[i].size() - 1 - j]);
//        }
//    }
//    for (int i = 0; i < x.size(); i++) {
//        if (x[i] == "\n") {
//            cout << x[i];
//        }
//        else {
//            cout << x[i] << ' ';
//        }
//    }
//	return 0;
//}