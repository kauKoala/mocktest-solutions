#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// a[i]와 a[j]가 서로소(최대공약수가 1)인 (i, j) 중 i + j 의 최댓값을 구하는 문제 (i == j 도 가능)

// n은 최대 2 * 10^5 이므로, 모든 (i, j) 쌍을 확인하면 약 4 * 10^10 번으로 시간 초과가 난다.
// 하지만 a[i]의 값은 1 ~ 1000 범위뿐이다.
// 같은 값이 여러 번 나오면, i + j 를 최대로 하려면 그 값의 "가장 마지막 인덱스"만 쓰면 된다.
// 따라서 값마다 마지막 인덱스만 저장해 두고,
// 값 x, y (1 ~ 1000) 쌍을 모두 확인하면서 gcd(x, y) == 1 이면 last[x] + last[y] 로 정답을 갱신한다.
// 값 쌍은 최대 1000 * 1000 = 10^6 개이므로 충분히 빠르다.

// 최대 값 선언
const int MAX_VAL = 1000;

// 최대공약수 함수 (유클리드 호제법)
int gcd(int x, int y) {
    // gcd(x, y) = gcd(y, x % y) 를 나머지가 0이 될 때까지 반복
    while (y != 0) {
        int r = x % y;
        x = y;
        y = r;
    }
    return x;
}

int main() {

    // 테스트 케이스 입력 처리
    int t;
    cin >> t;

    for (int _ = 0; _ < t; _++) {
        // 배열 길이 n 입력 처리
        int n;
        cin >> n;

        // 변수 선언
        vector<int> last(MAX_VAL + 1, 0);   // 값 x가 마지막으로 등장한 인덱스 (0이면 등장하지 않음)

        // 배열 입력 처리 (인덱스는 문제와 같이 1부터 사용)
        for (int i = 1; i <= n; i++) {
            int val;
            cin >> val;
            last[val] = i;   // 뒤에서 나온 인덱스로 계속 덮어쓰므로 마지막 인덱스가 남음
        }

        // 정답을 저장할 변수 선언 (서로소 쌍이 없으면 -1)
        int answer = -1;

        // 등장한 값 x, y 쌍을 모두 확인
        for (int x = 1; x <= MAX_VAL; x++) {
            if (last[x] == 0) continue;   // 등장하지 않은 값은 건너뜀

            for (int y = x; y <= MAX_VAL; y++) {   // (x, y)와 (y, x)는 결과가 같으므로 y >= x 만 확인
                if (last[y] == 0) continue;

                // 서로소라면 인덱스 합으로 정답 갱신
                if (gcd(x, y) == 1) {
                    answer = max(answer, last[x] + last[y]);
                }
            }
        }

        // 출력 처리
        cout << answer << "\n";
    }

    return 0;
}
