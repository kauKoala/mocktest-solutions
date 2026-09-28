#include <iostream>
#include <string>

using namespace std;

int main() {

    // 입력 처리
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string w;
        cin >> w;

        // 문자열 맨 끝의 "us"를 제외하고 "i"를 덧붙여 출력
        cout << w.substr(0, w.length() - 2) + "i" << "\n";
    }
    
    return 0;
}