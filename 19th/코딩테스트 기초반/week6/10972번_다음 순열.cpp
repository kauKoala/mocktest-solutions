#include <iostream>
#include <algorithm> // next_permutation 함수를 사용하기 위해 헤더 선언

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> V(N);
    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    // next_permutation은 다음 순서의 순열을 찾는 함수
    // 만약 다음 순서가 존재하면 true를 아니라면 false를 반환
    // 다음 순서가 존재하면 입력한 벡터를 다음 순서로 바꿈
    if (next_permutation(V.begin(), V.end())) { 
        for (int i = 0; i < N; i++) {
            cout << V[i] << " ";
        }
    }
    else {
        cout << -1;
    }
}