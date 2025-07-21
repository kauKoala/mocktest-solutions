#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        int ans = -1001; // 절댓값이 1,000보다 작음
        int sum = 0;

        cin >> N;

        int num;
        for (int i = 0; i < N; i++) {
            cin >> num;

            sum += num; // 입력받은 값을 더함
            ans = max(ans, sum); // 현재 ans와 sum의 값을 비교
            
            // 만약 sum이 0보다 작아지면 해당 원소는 Maximum subarray가 될 수 없음
            if (sum < 0) sum = 0; 
        }

        cout << ans << "\n";
    }
}