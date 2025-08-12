#include <iostream>
#include <vector>
#include <algorithm> // sort, next_permutation 함수를 사용하기 위해 헤더 선언

using namespace std;

int main() {
    int L, C;
    cin >> L >> C;

    vector<char> V(C);
    for (int i = 0; i < C; i++) {
        cin >> V[i];
    }

    sort(V.begin(), V.end()); // 사전순으로 출력하기 위해 정렬

    // c++에는 조합을 찾는 함수가 없음
    // 순열을 찾는 함수를 조합을 찾는 함수로 사용하기 위해 mask 벡터 선언
    // 조합의 수(L)만큼 0으로, 나머지는 1로 채움
    vector<int> mask(C, 1); 
    for (int i = 0; i < L; i++) {
        mask[i] = 0;
    }

    // next_permutation은 다음 순서의 순열을 찾는 함수
    // 만약 다음 순서가 존재하면 true를 아니라면 false를 반환
    // 다음 순서가 존재하면 입력한 벡터를 다음 순서로 바꿈
    // 위에서 선언한 mask 벡터에 대해서 next_permutation 함수를 사용
    // 0 0 0 0 1 1
    // 0 0 0 1 0 1
    // 0 0 0 1 1 0
    // ...
    // 1 0 1 0 0 0
    // 1 1 0 0 0 0
    do {
        vector<char> ans;
        int vowels = 0; // 모음
        int consonants = 0; // 자음
        for (int i = 0; i < C; i++) {
            if (!mask[i]) { // mask의 값이 0일 경우
                if (V[i] == 'a' || V[i] == 'e' || V[i] == 'i' || V[i] == 'o' || V[i] == 'u') vowels++;
                else consonants++;
                ans.push_back(V[i]);
            }
        }
        if (vowels >= 1 && consonants >= 2) { // 암호의 조건
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i];
            }
            cout << "\n";
        }
        
    } while (next_permutation(mask.begin(), mask.end()));
}