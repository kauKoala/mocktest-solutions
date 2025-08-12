#include <iostream>
#include <string>
#include <queue>

using namespace std;

bool visited[10000];

void bfs(int A, int B) {
    queue <pair<int, string>> q; // 지금까지 나왔던 명령어를 함께 저장

    visited[A] = true;
    q.push({ A, "" });

    while (!q.empty()) {
        int n = q.front().first;
        string cmd = q.front().second;
        q.pop();

        if (n == B) { // B에 도달하면 출력 후 break
            cout << cmd << "\n";
            break;
        }

        int res1, res2, res3, res4;

        // D 명령어
        res1 = (n * 2) % 10000;
        if (!visited[res1]) {
            visited[res1] = true;
            q.push({ res1, cmd + 'D' });
        }

        // S 명령어
        if (n == 0) res2 = 9999;
        else res2 = n - 1;
        if (!visited[res2]) {
            visited[res2] = true;
            q.push({ res2, cmd + 'S' });
        }

        // L 명령어
        res3 = (n % 1000) * 10 + n / 1000;
        if (!visited[res3]) {
            visited[res3] = true;
            q.push({ res3, cmd + 'L' });
        }

        // R 명령어
        res4 = (n % 10) * 1000 + n / 10;
        if (!visited[res4]) {
            visited[res4] = true;
            q.push({ res4, cmd + 'R' });
        }
    }
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int A, B;
        cin >> A >> B;

        fill(visited, visited + 10000, false); // visited 배열 초기화

        bfs(A, B);
    }
}