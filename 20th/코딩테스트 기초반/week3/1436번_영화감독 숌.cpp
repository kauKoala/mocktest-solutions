#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> V;

int main() {
    int cnt = 0;

    int num = 666; // 1번 종말의 수
    while (1) {
        // N이 10,000보다 작거나 같은 자연수이기에, cnt가 10,000보다 크면 종료
        if (cnt > 10000) break; 
        string str_num = to_string(num);

        bool is666 = false;
        // 숫자를 읽으며 연속한 세 숫자가 6일 경우 종말의 수
        for (int j = 0; j < str_num.length() - 2; j++) {
            if (str_num[j] == '6' && str_num[j + 1] == '6' && str_num[j + 2] == '6') {
                is666 = true;
            }
        }

        /// 666일 경우 벡터에 저장하고, cnt를 1 늘림
        if (is666) {
            V.push_back(num);
            cnt++;
        }
        num++; // 다음 숫자를 찾음
    }

    int N;
    cin >> N;

    cout << V[N - 1]; // 0번 인덱스부터 저장했기에 N - 1이 정답
}