#include <iostream>

using namespace std;

int main() {
    int s1, s2;
    cin >> s1 >> s2;

    int test_case, ans;
    bool sample_tc = true; // 샘플 테스트케이스가 틀리기 전에는 true
    for (int i = 0; i < s1; i++) {
        cin >> test_case >> ans;
        if (test_case != ans) sample_tc = false; // 샘플 테스트케이스가 한 번이라도 틀리면 false
    }
    bool system_tc = true; // 시스템 테스트케이스가 틀리기 전에는 true
    for (int j = 0; j < s2; j++) {
        cin >> test_case >> ans;
        if (test_case != ans) system_tc = false; // 시스템 테스트케이스가 한 번이라도 틀리면 false
    }

    if (sample_tc) {
        if (system_tc) cout << "Accepted"; // 샘플 & 시스템 모두 통과
        else cout << "Why Wrong!!!"; // 샘플 통과, 시스템 틀림
    }
    else cout << "Wrong Answer"; // 샘플 틀림
}