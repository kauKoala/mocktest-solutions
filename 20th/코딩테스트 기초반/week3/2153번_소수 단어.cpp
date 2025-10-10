#include <iostream>
#include <string>

using namespace std;

bool not_prime[1041]; // 소수를 찾기 위함

int main() {
    for (int i = 2; i < 1041; i++) {
        if (not_prime[i] == true) continue; // 이미 소수가 아닐 경우 continue
        
        int mul = 2; // 2의 배수
        while (i * mul < 1041) {
            not_prime[i * mul] = true; // i의 2 이상의 배수는 소수가 아님
            mul++; // 배수를 늘림(3, 4, ...)
        }
    }

    string S;
    cin >> S;

    int sum = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] >= 'a' && S[i] <= 'z') sum += S[i] - 'a' + 1; // 소문자일 경우
        else sum += S[i] - 'A' + 27; // 대문자일 경우
    }

    // 입력의 합이 소수인지 아닌지 구함
    if (not_prime[sum]) cout << "It is not a prime word.";
    else cout << "It is a prime word.";
}