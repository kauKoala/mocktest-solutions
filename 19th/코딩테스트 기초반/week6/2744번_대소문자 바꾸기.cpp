#include <iostream>
#include <string>

using namespace std;

int main() {
    string str;
    cin >> str;

    // A는 아스키코드로 65
    // a는 아스키코드로 97
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'a' && str[i] <= 'z') { // 소문자일 경우
            // a를 빼고 A를 더함
            // ex) str[i] = e
            //     'e'(101) - 'a'(97) = 4
            //     4 + 'A'(65) = 'E'(69)
            cout << char(str[i] - 'a' + 'A'); 
        }
        else { // 대문자일 경우
            // A를 빼고 a를 더함
            // ex) str[i] = E
            //     'E'(69) - 'A'(65) = 4
            //     4 + 'a'(97) = 'e'(101)
            cout << char(str[i] - 'A' + 'a'); 
        }
    }
}