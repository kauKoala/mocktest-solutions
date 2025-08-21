#include <iostream>
#include <queue>

using namespace std;

bool visited[1001][1001]; // 방문 여부, 화면 이모티콘 개수 & 클립보드 이모티콘 개수

int main() {
    int S;
    cin >> S;

    queue<pair<pair<int, int>, int>> q; // 화면 이모티콘 개수, 클립보드 이모티콘 개수, 시간
    visited[1][0] = true;
    q.push({ {1, 0}, 0 });

    while (!q.empty()) {
        int emoticon_num = q.front().first.first; // 화면 이모티콘 개수
        int clipboard_num = q.front().first.second; // 클립보드 이모티콘 개수
        int time = q.front().second; // 시간
        q.pop();

        if (emoticon_num == S) { 
            cout << time;
            break;
        }
        
        // 1번 연산
        if (!visited[emoticon_num][emoticon_num]) { 
            visited[emoticon_num][emoticon_num] = true;
            q.push({ {emoticon_num, emoticon_num}, time + 1 });
        }
        // 2번 연산
        if (emoticon_num + clipboard_num <= 1000 && !visited[emoticon_num + clipboard_num][clipboard_num]) {
            visited[emoticon_num + clipboard_num][clipboard_num] = true;
            q.push({ {emoticon_num + clipboard_num, clipboard_num}, time + 1 });
        }
        // 3번 연산
        if (emoticon_num - 1 > 0 && !visited[emoticon_num - 1][clipboard_num]) {
            visited[emoticon_num - 1][clipboard_num] = true;
            q.push({ {emoticon_num - 1, clipboard_num}, time + 1 });
        }
    }
}