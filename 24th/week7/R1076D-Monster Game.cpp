#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

// 난이도 x를 정하면 강도가 x 이상인 검만 사용할 수 있고,
// 점수는 'x * 클리어한 레벨 수' 이다. 이 점수의 최댓값을 구하는 문제이다.

// 먼저, 난이도 x의 후보를 줄인다.
// x를 키우면 쓸 수 있는 검의 수는 줄어들거나 그대로이다.
// 쓸 수 있는 검의 수가 똑같다면 x는 클수록 이득이므로,
// x는 검의 강도 a[i] 중 하나로만 정해도 충분하다.

// 검은 한 번 치면 부러지므로, 검 k개로는 총 k번만 칠 수 있다.
// 레벨은 1번부터 순서대로 깨야 하므로, b의 누적합이 k이하인 가장 긴 앞부분까지 클리어할 수 있다.

// a를 내림차순으로 정렬하고, 레벨을 가리키는 포인터를 앞으로만 움직이는 투 포인터로 처리한다.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        int n;
        cin >> n;

        vector<long long> a(n);
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        // 강도가 큰 검부터 보도록 내림차순 정렬
        sort(a.begin(), a.end(), greater<long long>());

        long long answer = 0;
        int level = 0;      // 지금까지 클리어한 레벨 수
        long long used = 0; // 클리어한 레벨들에 사용한 검의 수

        for (int i = 0; i < n; i++) {
            int swords = i + 1; // 난이도를 a[i]로 정했을 때 쓸 수 있는 검의 수

            // 남은 검으로 다음 레벨을 깰 수 있는 동안 계속 진행
            while (level < n && used + b[level] <= swords) {
                used += b[level];
                level++;
            }

            // 점수 = 난이도 * 클리어한 레벨 수
            answer = max(answer, a[i] * level);
        }

        // 출력 처리
        cout << answer << "\n";
    }

    return 0;
}

