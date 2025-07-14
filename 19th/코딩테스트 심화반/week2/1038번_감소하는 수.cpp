#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int increase_num[11];

vector<long long> V;

// 현재 숫자, 현재 자릿수, 총 자릿수
void back_tracking(int current_num, int current_digit, int total_digit) {
    if (current_digit > total_digit) {
        string decrease_num = "";
        for (int i = total_digit; i > 0; i--) { // 배열을 역으로 조회하여 감소하는 수 획득
            decrease_num += increase_num[i] + '0';
        }

        V.push_back(stoll(decrease_num));
        return;
    }
    for (int j = current_num + 1; j < 10; j++) { // 현재 숫자보다 큰 숫자만 입력
        increase_num[current_digit] = j;
        back_tracking(j, current_digit + 1, total_digit);
    }
}

int main() {
    for (int i = 1; i <= 10; i++) { // 자릿수 설정
        for (int j = 0; j < 10; j++) { // 0 ~ 9까지의 숫자 입력
            increase_num[1] = j;
            back_tracking(j, 2, i);
        }
    }

    sort(V.begin(), V.end()); // 모든 감소하는 수를 크기 순으로 정렬

    int N;
    cin >> N;
    if (N >= V.size()) cout << -1;
    else cout << V[N];
}