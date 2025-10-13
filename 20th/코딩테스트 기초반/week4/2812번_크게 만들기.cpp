#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int N, K;
    string str;

    cin >> N >> K;
    cin >> str;

    stack<char> s;

    string ans_right = ""; // 만약 지울 수 있는 숫자가 0일 경우 나머지는 바로 string으로 저장
    for (int i = 0; i < str.length(); i++) {
        if (K == 0) {
            ans_right = str.substr(i); 
            break;
        }
        // 스택이 비어있지 않고, 지울 수 있는 숫자가 0보다 커야 함
        // 현재 숫자가 스택의 top에 있는 숫자보다 작거나 같을 때 까지 스택의 원소를 pop
        while (!s.empty() && K > 0 && s.top() < str[i]) { 
            s.pop();
            K--;
        }
        s.push(str[i]);
    }

    while (K--) { // 만약 지울 수 있는 숫자가 남았을 경우 그만큼 스택에서 pop
        s.pop();
    }

    string ans_left = "";
    while (!s.empty()) {
        ans_left = s.top() + ans_left; // 스택의 top부터 역순으로 저장해야 함
        s.pop();
    }

    cout << ans_left + ans_right;
}