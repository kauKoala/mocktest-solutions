#include <iostream>
#include <vector>
#include <algorithm> // sort 함수를 위해 헤더 파일 선언

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> V(N); // 벡터를 N 크기로 초기화

        int test1, test2;
        for (int i = 0; i < N; i++) {
            cin >> test1 >> test2;
            V[i] = {test1, test2};
        }

        sort(V.begin(), V.end()); // test1에 대해서 우선 정렬(오름차순)

        int test2_rank = N + 1; // test2의 순위가 test2_rank보다 더 높으면(1위에 가까우면) 정답에 포함(test1이 순위대로 정렬되어있기 때문)
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (V[i].second < test2_rank) { // 만약 test2_rank보다 순위가 높을 경우(1위에 가까울 경우)
                ans++;
                test2_rank = V[i].second; // test2_rank 갱신
            }
        }
        
        cout << ans << "\n";
    }
}