#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string str;
    vector<int> cnt_num(10, 0);  // 크기 10, 모든 값이 0

    cin >> str;
    
    for (int i = 0; i < str.length(); i++) {
        int num = str[i] - '0'; // char 형태의 숫자를 int 형으로 저장
        cnt_num[num]++; // num에 해당하는 숫자의 개수를 1 증가
    }

    
    int ans = 0; // ans 초기화
    
    // 6과 9는 같이 사용할 수 있기에, 더하고 2로 나누면 사용해야 할 세트의 개수를 알 수 있음
    // c++에서 나눗셈 연산은 내림 연산이기에 1을 더해줌
    int six_nine_cnt = (cnt_num[6] + cnt_num[9] + 1) / 2;
    
    ans = six_nine_cnt; // ans의 값을 6과 9일 경우를 고려하여 설정
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue; // 6과 9일 경우 패스
        else ans = max(ans, cnt_num[i]); // 기존의 ans 값보다 클 경우 ans 갱신
    }

    cout << ans;
}