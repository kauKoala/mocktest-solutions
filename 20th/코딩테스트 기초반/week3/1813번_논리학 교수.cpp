#include <iostream>
#include <map>

using namespace std;

int true_list[51]; // 입력 i의 개수

int main() {
    int N;
    cin >> N;

    while (N--) {
        int i;
        cin >> i;

        true_list[i]++; // i의 개수를 저장
    }

    bool impossible = true;
    // N이 50보다 작거나 같기에 최대 값은 50
    for (int i = 50; i >= 0; i--) {
        // i개의 말이 i개 존재하면 그 말은 참
        // ex) 정확하게 2개의 말은 참이다. 라는 문장이 두 번 나와야만 답이 될 수 있음
        if (true_list[i] == i) { 
            impossible = false;
            cout << i;
      
            break; // 가능한 답이 여러가지일 경우 가장 큰 값을 출력하기 위해 반복문 중단
        }
    }

    // 위에서 답이 나오지 않았을 경우 모순
    if (impossible) cout << -1;
}