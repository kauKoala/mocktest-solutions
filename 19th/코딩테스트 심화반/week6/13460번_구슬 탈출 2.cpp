#include <iostream>
#include <queue>

using namespace std;

char map[11][11];
bool visited[11][11][11][11]; // 빨간 구슬(r, c)과 파란 구슬(r, c)의 방문 여부

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    int rr, rc, br, bc; // 빨간 구슬의 r, c와 파란 구슬의 r, c 저장
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 'R') {
                rr = i;
                rc = j;
                map[i][j] = '.'; // 구슬은 r, c 위치로만 저장
            }
            if (map[i][j] == 'B') {
                br = i;
                bc = j;
                map[i][j] = '.'; // 구슬은 r, c 위치로만 저장
            }
        }
    }

    // 최단 거리를 찾기 위해 BFS 사용
    // 빨간 구슬의 r, c와 파란 구슬의 r, c, 이동한 횟수 저장
    queue < pair<pair<pair<int, int>, pair<int, int>>, int>> q; 

    visited[rr][rc][br][bc] = true;
    q.push({ {{rr, rc}, {br, bc}}, 0 });

    while (!q.empty()) {
        int nrr = q.front().first.first.first;
        int nrc = q.front().first.first.second;
        int nbr = q.front().first.second.first;
        int nbc = q.front().first.second.second;
        int dist = q.front().second;
        q.pop();

        if (dist >= 10) { // 이미 dist가 10일 경우 구슬은 이동할 수 없음
            cout << -1;
            return 0;
        }

        // 1. 왼쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (bc < rc) { // 파란 구슬이 빨간 구슬보다 왼쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[br][bc - 1] == '.') bc--; // 왼쪽으로 기울임
            while (map[rr][rc - 1] == '.' && (rr != br || rc - 1 != bc)) rc--; // 파란 구슬을 고려하며 왼쪽으로 기울임

            if (map[br][bc - 1] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr][rc - 1] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            } 
        }
        else { // 빨간 구슬이 파란 구슬보다 왼쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[rr][rc - 1] == '.') rc--; // 왼쪽으로 기울임
            while (map[br][bc - 1] == '.' && (rr != br || rc != bc - 1)) bc--; // 빨간 구슬을 고려하며 왼쪽으로 기울임

            if (map[br][bc - 1] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr][rc - 1] == 'O' && map[br][bc - 2] != 'O') { // 빨간 구슬이 구멍에 들어가고도 파란 구슬이 구멍에 들어가지 않는 경우
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }
        }

        // 2. 오른쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (bc > rc) { // 파란 구슬이 빨간 구슬보다 오른쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[br][bc + 1] == '.') bc++; // 오른쪽으로 기울임
            while (map[rr][rc + 1] == '.' && (rr != br || rc + 1 != bc)) rc++; // 파란 구슬을 고려하며 오른쪽으로 기울임

            if (map[br][bc + 1] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr][rc + 1] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }
        }
        else { // 빨간 구슬이 파란 구슬보다 오른쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[rr][rc + 1] == '.') rc++; // 오른쪽으로 기울임
            while (map[br][bc + 1] == '.' && (rr != br || rc != bc + 1)) bc++; // 빨간 구슬을 고려하며 오른쪽으로 기울임

            if (map[br][bc + 1] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr][rc + 1] == 'O' && map[br][bc + 2] != 'O') { // 빨간 구슬이 구멍에 들어가고도 파란 구슬이 구멍에 들어가지 않는 경우
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }   
        }

        // 3. 위쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (br < rr) { // 파란 구슬이 빨간 구슬보다 위쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[br - 1][bc] == '.') br--; // 위쪽으로 기울임
            while (map[rr - 1][rc] == '.' && (rr - 1 != br || rc != bc)) rr--; // 파란 구슬을 고려하며 위쪽으로 기울임

            if (map[br - 1][bc] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr - 1][rc] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }  
        }
        else { // 빨간 구슬이 파란 구슬보다 위쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[rr - 1][rc] == '.') rr--; // 위쪽으로 기울임
            while (map[br - 1][bc] == '.' && (rr != br - 1 || rc != bc)) br--; // 빨간 구슬을 고려하며 위쪽으로 기울임

            if (map[br - 1][bc] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr - 1][rc] == 'O' && map[br - 2][bc] != 'O') { // 빨간 구슬이 구멍에 들어가고도 파란 구슬이 구멍에 들어가지 않는 경우
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }    
        }

        // 4. 아래쪽으로 기울이기
        rr = nrr, rc = nrc, br = nbr, bc = nbc;
        if (br > rr) { // 파란 구슬이 빨간 구슬보다 아래쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[br + 1][bc] == '.') br++; // 아래쪽으로 기울임
            while (map[rr + 1][rc] == '.' && (rr + 1 != br || rc != bc)) rr++; // 파란 구슬을 고려하며 아래쪽으로 기울임

            if (map[br + 1][bc] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr + 1][rc] == 'O') {
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }       
        }
        else { // 빨간 구슬이 파란 구슬보다 아래쪽에 있는 경우 고려 (구슬은 겹칠 수 없음)
            while (map[rr + 1][rc] == '.') rr++; // 아래쪽으로 기울임
            while (map[br + 1][bc] == '.' && (rr != br + 1 || rc != bc)) br++; // 빨간 구슬을 고려하며 아래쪽으로 기울임

            if (map[br + 1][bc] != 'O') { // 파란 구슬이 구멍에 들어가지 않는 경우
                if (map[rr + 1][rc] == 'O' && map[br + 2][bc] != 'O') { // 빨간 구슬이 구멍에 들어가고도 파란 구슬이 구멍에 들어가지 않는 경우
                    cout << dist + 1;
                    return 0;
                }

                if (!visited[rr][rc][br][bc]) {
                    visited[rr][rc][br][bc] = true;
                    q.push({ {{rr, rc}, {br, bc}}, dist + 1 });
                }
            }      
        }

    }

    cout << -1;
}