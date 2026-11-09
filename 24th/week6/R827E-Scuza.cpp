#include <iostream>
#include <vector>

using namespace std;

// 다리 길이가 k일 때, 계단을 앞에서부터 올라가서 도달할 수 있는 최대 높이를 구하는 문제

// 계단은 앞에서부터 순서대로만 오를 수 있으므로,
// 다리 길이 k보다 높은 계단(a[j] > k)을 처음 만나는 순간 더 이상 올라갈 수 없다.
// 즉, "앞에서부터 처음으로 a[j] > k 인 위치" 직전까지의 높이 합이 정답이다.

// 질문 q가 최대 2 * 10^5 이므로, 질문마다 계단을 처음부터 확인하면 시간 초과가 난다.
// 1. prefix_max[i] : 1 ~ i번 계단 중 가장 높은 계단 (i번 계단까지 오를 수 있는지 = prefix_max[i] <= k)
// 2. prefix_sum[i] : 1 ~ i번 계단 높이의 합 (i번 계단까지 올랐을 때의 높이)
// prefix_max는 뒤로 갈수록 줄어들지 않으므로(오름차순), 이분 탐색으로
// prefix_max[i] > k 인 첫 번째 위치를 찾으면, 그 직전 위치의 prefix_sum이 정답이다.

// 이분 탐색 함수
int binary_search(const vector<long long>& arr, long long target) {
    int left = 0;
    int right = arr.size();

    // 배열에서 타겟보다 큰 첫 번째 원소의 인덱스를 반환 (없으면 배열 크기 반환)
    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= target) {
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
        // 계단 수 n, 질문 수 q 입력 처리
        int n, q;
        cin >> n >> q;

        // 변수 선언
        vector<long long> prefix_max(n);       // prefix_max[i] : 0 ~ i번 계단 중 가장 높은 계단
        vector<long long> prefix_sum(n + 1, 0); // prefix_sum[i] : 앞에서부터 i개 계단 높이의 합 (prefix_sum[0] = 0)

        // 계단 높이 입력 및 누적 최댓값, 누적합 계산
        for (int i = 0; i < n; i++) {
            long long a;
            cin >> a;

            if (i == 0) {
                prefix_max[i] = a;
            } else {
                prefix_max[i] = max(prefix_max[i - 1], a);
            }
            prefix_sum[i + 1] = prefix_sum[i] + a;
        }

        // 질문 처리
        for (int i = 0; i < q; i++) {
            long long k;
            cin >> k;

            // 처음으로 오를 수 없는 계단의 위치 = 오를 수 있는 계단의 개수
            int cnt = binary_search(prefix_max, k);

            // 오를 수 있는 계단들의 높이 합 출력 (공백으로 구분)
            cout << prefix_sum[cnt] << " ";
        }
        cout << "\n";
    }

    return 0;
}
