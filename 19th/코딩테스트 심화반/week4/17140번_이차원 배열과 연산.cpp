#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int arr[101][101]; // r과 c는 100을 넘지 않음

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> arr[i][j];
        }
    }

    int r_size = 3, c_size = 3;

    int ans = 0; // 현재 시간

    while (ans <= 100) { // 최대 100초
        if (arr[r][c] == k) break; // 정답을 찾으면 break
        ans++;

        if (r_size >= c_size) {
            int max_size = 0; // R 연산을 마친 후 가장 긴 행의 크기를 저장하기 위함
            for (int i = 1; i <= r_size; i++) {
                unordered_map<int, int> m; // 각 원소가 몇 번 나왔는지 알기 위함
                for (int j = 1; j <= c_size; j++) {
                    int tmp = arr[i][j];
                    if (tmp != 0) m[tmp]++;
                }

                vector<pair<int, int>> v;
                for (auto x : m) {
                    v.push_back({ x.second, x.first }); // 각 원소가 나온 횟수를 우선적으로 정렬하기 위함
                }

                sort(v.begin(), v.end());

                int size = v.size();
                for (int j = 0; j < size; j++) {
                    arr[i][2 * j + 1] = v[j].second;
                    arr[i][2 * j + 2] = v[j].first;
                }
                for (int j = 2 * size + 1; j <= c_size; j++) { // R 연산 이전에 남아있던 수들을 지우기 위함
                    arr[i][j] = 0;
                }
                max_size = max(max_size, size * 2);
            }
            c_size = max_size; // 모든 연산을 마치면 max_size로 열의 개수를 갱신
        }
        else {
            int max_size = 0; // C 연산을 마친 후 가장 긴 열의 크기를 저장하기 위함
            for (int j = 1; j <= c_size; j++) {
                unordered_map<int, int> m; // 각 원소가 몇 번 나왔는지 알기 위함
                for (int i = 1; i <= r_size; i++) {
                    int tmp = arr[i][j];
                    if (tmp != 0) m[tmp]++;
                }

                vector<pair<int, int>> v;
                for (auto x : m) {
                    v.push_back({ x.second, x.first }); // 각 원소가 나온 횟수를 우선적으로 정렬하기 위함
                }

                sort(v.begin(), v.end());

                int size = v.size();
                for (int i = 0; i < size; i++) {
                    arr[2 * i + 1][j] = v[i].second;
                    arr[2 * i + 2][j] = v[i].first;
                }
                for (int i = 2 * size + 1; i <= r_size; i++) { // C 연산 이전에 남아있던 수들을 지우기 위함
                    arr[i][j] = 0;
                }
                max_size = max(max_size, size * 2);
            }
            r_size = max_size; // 모든 연산을 마치면 max_size로 행의 개수를 갱신
        }
    }

    if (ans <= 100) cout << ans;
    else cout << -1;
}