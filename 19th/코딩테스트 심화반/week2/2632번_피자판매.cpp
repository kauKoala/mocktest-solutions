#include <iostream>

using namespace std;

int subset_sum[2000001];

int A[1001];
int B[1001];

int main() {
    int size;
    int m, n;
    
    int sum_a = 0; // A 피자의 사이즈
    int sum_b = 0; // B 피자의 사이즈

    cin >> size;
    cin >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> A[i];
        sum_a += A[i]; 
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
        sum_b += B[i];
    }

    subset_sum[0]++; // A 피자가 들어가지 않을 경우
    subset_sum[sum_a]++; // A 피자가 전부 들어갈 경우

    for (int i = 0; i < m; i++) {
        int sum = 0;

        for (int j = 0; j < m - 1; j++) {
            sum += A[(i + j) % m]; // 조각 i를 시작으로 연속된 조각들을 더함
            subset_sum[sum]++; 
        }
    }

    int ans = subset_sum[size]; // B 피자가 들어가지 않을 경우
    for (int i = 0; i < n; i++) {
        int sum = 0;

        for (int j = 0; j < n - 1; j++) {
            sum += B[(i + j) % n]; // 조각 i를 시작으로 연속된 조각들을 더함
            if (size - sum >= 0) ans += subset_sum[size - sum]; // 고객이 원하는 피자 사이즈가 있는지 확인
        }
    }
    if (size - sum_b >= 0) ans += subset_sum[size - sum_b]; // B 피자가 전부 들어갈 경우

    cout << ans;
}