#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 이진수들의 곱으로 표현될 수 있는 십진수를 구하는 문제

// n의 범위(이진수 표현 기준 십만) 안에 있는 십진수들을 
// 이진수로 변환시켜 배열에 미리 저장해 둔다
vector<int> binary_arr;

// 정답을 저장해 둘 배열
// dp[i]가 True면 i는 이진 십진수들의 곱으로 표현 가능
bool dp[100001];

int main() {
    for (int i = 2; i < 33; i++) {
        // C++에서는 bitset이나 반복문을 통해 2진수 문자열로 변환 가능
        string s = "";
        int temp = i;
        while (temp > 0) {
            s = to_string(temp % 2) + s;
            temp /= 2;
        }
        binary_arr.push_back(stoi(s));
    }

    // 초기값 삽입
    dp[1] = true;

    for (int i = 1; i <= 100000; i++) {
        // i가 이진십진수들의 곱으로 표현 가능한 경우
        if (dp[i]) {

            // 또 다른 이진십진수들이 곱해진 수도 이진십진수 임을 연산
            for (int binary : binary_arr) {
                long long mult = 1LL * i * binary;

                // n범위를 벗어나는 경우 대입연산을 하지 않기 위한 조건문
                if (mult <= 100000) {
                    dp[mult] = true;
                }
            }
        }
    }

    // 입력 처리
    int t;
    cin >> t;

    for (int tc = 0; tc < t; tc++) {
        int n;
        cin >> n;

        // 출력 처리
        if (dp[n]) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}