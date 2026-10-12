#include <iostream>
#include <string>

using namespace std;

// s의 ? 문자를 소문자로 바꿔, t가 s의 부분 수열이 되도록 하는 문제

// 일찍 t의 글자를 소비해도 뒤 ?나 고정 글자로 나머지를 맞출 수 있고,
// 앞쪽을 비워 두면 뒤에서만 맞춰야 해 불가능해질 수 있으므로,
// 그리디 방식으로 접근한다.

// s문자열을 한 번 탐색하며 t의 앞에서부터 맞출 위치를 찾고,
// s의 i번째 글자가 t의 다음 글자와 같거나 ?이면, 그 자리에 t의 글자를 넣고 t 진행 인덱스를 1 증가시킨다.
// t를 모두 맞춘 뒤 남은 ?는 아무 소문자로 채우면 된다.

int main() {

    // 테스트 케이스 입력 처리
    int T;
    cin >> T;

    for (int _ = 0; _ < T; _++) {
        string s, t;
        cin >> s >> t;

        // 변수 선언
        int t_length = t.length();
        int t_idx = 0;  // 현재 맞춰야 할 t의 인덱스

        for (int i = 0; i < (int)s.length(); i++) {
            // 아직 맞출 t가 남았고, s[i]가 다음 t 글자와 같거나 ?이면 그 자리에 배치
            if (t_idx < t_length && (s[i] == t[t_idx] || s[i] == '?')) {
                s[i] = t[t_idx];
                t_idx++;
            }
            // t 맞추기에는 쓰지 않는 ?는 아무 문자로 채움
            else if (s[i] == '?') {
                s[i] = 'a';      // 아무 문자로 a 선택
            }
        }

        // 출력 처리
        if (t_idx == t_length) {
            cout << "YES\n";
            cout << s << "\n";
        } else {   // s를 끝까지 탐색하였어도 t를 다 맞추지 못했다면 불가능
            cout << "NO\n";
        }
    }

    return 0;
}
