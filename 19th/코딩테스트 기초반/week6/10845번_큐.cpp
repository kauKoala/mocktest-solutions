#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main() {
    int N;
    queue<int> q;
    string cmd;

    cin >> N; // 명령의 수

    while (N--) {
        cin >> cmd; // 명령어

        if (cmd == "push") { // push 명령어
            int X;
            cin >> X;
            q.push(X);
        }

        if (cmd == "pop") { // pop 명령어
            if (q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }

        if (cmd == "size") cout << q.size() << "\n"; // size 명령어

        if (cmd == "empty") { // empty 명령어
            if (q.empty()) cout << 1 << "\n";
            else cout << 0 << "\n";
        }

        if (cmd == "front") { // front 명령어
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }

        if (cmd == "back") { // back 명령어
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}