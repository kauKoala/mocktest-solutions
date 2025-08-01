#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string N;
    cin >> N;

    int M;
    cin >> M;

    char c; // 명령어
    char value; // P일 경우 추가로 입력받을 값

    stack<char> left; // 커서 왼쪽
    stack<char> right; // 커서 오른쪽

    // 초기 커서가 제일 오른쪽에 위치함으로 모든 값은 left에 존재
    for (int i = 0; i < N.size(); i++) {
        left.push(N[i]); 
    }

    while (M--) {
        cin >> c;
        if (c == 'L') { // L일 경우 커서를 왼쪽으로 이동, left의 top을 right로 push
            if (!left.empty()) {
                right.push(left.top());
                left.pop();
            }
        }
        if (c == 'D') { // D일 경우 커서를 오른쪽으로 이동, right의 top을 left로 push
            if (!right.empty()) {
                left.push(right.top());
                right.pop();
            }
        }
        if (c == 'B') { // B일 경우 커서 왼쪽의 값을 삭제, left의 top을 pop
            if (!left.empty()) {
                left.pop();
            }
        }
        if (c == 'P') { // P일 경우 커서 왼쪽에 값을 추가, left에 입력받은 value를 push
            cin >> value;

            left.push(value);
        }
    }

    // 제일 앞 숫자부터 출력하기 위해 left의 모든 값을 right로 보냄
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}