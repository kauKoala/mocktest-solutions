#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    // 양쪽에 최댓값이 존재할 경우를 위함
    // 더 멀리 떨어져있으면 이길 확률이 높음
    int left_dist = -1; // 중앙으로부터 떨어진 거리
    int right_dist = -1; // 중앙으로부터 떨어진 거리

    int max_value = -1;
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;

        if (i < N / 2) { // 왼쪽일 경우
            if (max_value < num) { // max 갱신
                max_value = num;
                left_dist = N / 2 - i;
            }
        }
        else { // 오른쪽일 경우
            if (max_value < num) { // max 갱신
                max_value = num;
                right_dist = i - N / 2 + 1;

                left_dist = -1; // 왼쪽에는 최댓값이 존재하지 않게 됨
            }
            else if (max_value == num) { // 이미 최댓값이 존재할 경우
                right_dist = i - N / 2 + 1; // 더 멀리 떨어져있어야 하기에 갱신
            }
        }
    }

    if (left_dist > right_dist) cout << "R"; // 왼쪽일 경우 홍팀
    else if (left_dist < right_dist) cout << "B"; // 오른쪽일 경우 청팀
    else cout << "X";
}