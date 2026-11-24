#include <iostream>
#include <vector>

using namespace std;

// 표지판 위치 a와 도착 시각 b가 주어질 때, 지점 d에 도착하는 시각(소수점 버림)을 구하는 문제

// 1. 표지판 사이에서는 속도가 일정하므로, d가 속한 구간 [a[i-1], a[i]]만 알면 시각을 계산할 수 있다.
//    구간 안에서 이동한 거리 비율만큼 시간이 흐르므로
//      시각 = b[i-1] + (d - a[i-1]) * (b[i] - b[i-1]) / (a[i] - a[i-1])
//    나눗셈을 마지막에 해야 소수점 아래를 잃지 않고 정확히 버림할 수 있다.
// 2. 출발점 (0, 0)을 맨 앞에 추가해 두면, 첫 구간도 같은 식으로 처리할 수 있다.
// 3. 질문 q가 최대 10^5개이므로 질문마다 구간을 처음부터 찾으면 시간 초과가 난다.
//    a는 오름차순이므로, 이분 탐색으로 "d 이상인 첫 번째 a[i]"를 찾는다.
// 4. 곱셈 결과는 최대 10^9 * 10^9 = 10^18 이므로 long long을 사용한다.

// 이분 탐색 함수
int binary_search(const vector<long long>& arr, long long target) {
    int left = 0;
    int right = arr.size();

    // 배열에서 타겟보다 크거나 같은 첫 번째 원소의 인덱스를 반환
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 목적지 n, 표지판 수 k, 질문 수 q 입력 처리
        long long n;
        int k, q;
        cin >> n >> k >> q;

        // 변수 선언 (맨 앞에 출발점 0을 추가하므로 크기는 k + 1)
        vector<long long> a(k + 1, 0);   // a[i] : i번째 표지판 위치 (a[0] = 0)
        vector<long long> b(k + 1, 0);   // b[i] : i번째 표지판 도착 시각 (b[0] = 0)

        // 표지판 위치, 도착 시각 입력 처리
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }

        // 질문 처리
        for (int j = 0; j < q; j++) {
            long long d;
            cin >> d;

            // d 이상인 첫 번째 표지판 찾기
            int i = binary_search(a, d);

            // 변수 선언
            long long answer;   // 지점 d에 도착하는 시각

            // d가 표지판 위치와 정확히 같다면 그 표지판의 도착 시각이 정답
            if (a[i] == d) {
                answer = b[i];
            }
            // 아니라면 구간 [a[i-1], a[i]] 안에 있으므로 비율로 계산 (곱셈을 먼저, 나눗셈을 나중에)
            else {
                answer = b[i - 1] + (d - a[i - 1]) * (b[i] - b[i - 1]) / (a[i] - a[i - 1]);
            }

            // 출력 처리 (공백으로 구분)
            cout << answer << " ";
        }
        cout << "\n";
    }

    return 0;
}
