#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    cin >> str;

    stack<int> S; // 현재까지 나온 레이저 개수를 저장
    int laser_cnt = 0;
    int ans = 0;
    bool is_laser = false; // 레이저인지 쇠막대기인지 판단하기 위함

    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '(') {
            S.push(laser_cnt);
            is_laser = true;
        }
        else {
            if (is_laser) laser_cnt++; // 만약 레이저라면 cnt 증가
            else ans += laser_cnt - S.top() + 1; // 쇠막대기라면 쇠막대기 시작 이후 나온 레이저 개수 + 1 만큼 ans에 더한다.

            S.pop();
            is_laser = false;
        }
    }

    cout << ans;
}