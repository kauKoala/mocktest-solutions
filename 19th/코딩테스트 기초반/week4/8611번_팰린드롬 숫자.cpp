#include <iostream>
#include <string>

using namespace std;

// 10^1000이기에 string으로 계산해야 함
// string용 나눗셈 함수 생성
// divide 함수는 몫과 나머지를 반환
pair<string, int> divide(string num, int base) { 
    string res = "";
    int remainder = 0; // 현재 나머지

    for (int i = 0; i < num.size(); i++) {
        // 제일 앞 자리(높은 자리수) 수부터 나누고, 만약 이전에 나누지 못한 수가 있을 경우 10을 곱한 후 현재 자리의 수를 더함
        int current = remainder * 10 + (num[i] - '0');
        if (!res.empty() || current / base != 0) res += char('0' + current / base); // 몫의 맨 앞에 0이 들어가는 것을 방지
        remainder = current % base; // 현재의 나머지 갱신
    }

    if (res.empty()) res = "0"; // 몫이 없을 경우 0 반환
    return {res, remainder};
}

// 진법 변환 함수
string convert(string num, int base) {
    string res = "";

    while (num != "0") {
        pair<string, int> divided_value = divide(num, base);
        res = char('0' + divided_value.second) + res; // 변환하고자 하는 진법(base)으로 나눈 나머지를 낮은 자리부터 저장
        num = divided_value.first; // 변환해야 할 수
    }

    return res;
}

int main() {
    string num;
    cin >> num;

    bool is_palindrome = false; // 팰린드롬인 경우가 있는지 판단하기 위함
    for (int i = 2; i <= 10; i++) {
        string tmp = convert(num, i);
        bool is_passible = true; // 현재의 진법으로 변환된 값이 팰린드롬인지 판단하기 위함

        int size = tmp.size();
        for (int j = 0; j <= size / 2; j++) {
            // 중앙을 기준으로 같은 거리에 있는 값들이 다를 경우 팰린드롬이 아님
            if (tmp[j] != tmp[size - j - 1]) {
                is_passible = false;
                break;
            }
        }

        if (is_passible) { // 팰린드롬일 경우
            is_palindrome = true; // 팰린드롬인 경우가 있기에 true로 갱신
            cout << i << " " << tmp << "\n";
        }
    }

    if (!is_palindrome) { // 팰린드롬인 경우가 없는 경우
        cout << "NIE";
    }
}