#include <iostream>
#include <string>

using namespace std;

int main() {
    // 입력으로 주어진 24시간을 12시간 포맷으로 전환하는 문제

    // 입력처리
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        
        string h = s.substr(0, 2);
        string m = s.substr(3, 2); 

        // 12시를 넘은 오후이면서 시간(hh)이 두 자릿수(22~24시)인 경우
        if (h >= "22") {
            cout << to_string(stoi(h) - 12) << ":" << m << " PM\n";
        }
        // 오후이면서 시간이 한 자릿수이어서 앞에 0이 붙는 경우
        else if (h >= "13") {
            cout << "0" << to_string(stoi(h) - 12) << ":" << m << " PM\n";
        }
        // 12:00~12:59 사이인 경우
        else if (h == "12") {
            cout << h << ":" << m << " PM\n";
        }
        // 00:00~00:59 사이인 경우
        else if (h == "00") {
            cout << "12:" << m << " AM\n";
        }
        // 01:00~11:59
        else {
            cout << h << ":" << m << " AM\n";
        }
    }

    return 0;
}