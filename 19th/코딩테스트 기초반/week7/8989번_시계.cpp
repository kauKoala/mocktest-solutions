#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    string t[5]; // 5개의 시간
    while (T--) {
        vector<pair<int, pair<int, int>>> v; // 각도, 시간, 시간의 idx 저장
        for (int i = 0; i < 5; i++) {
            cin >> t[i];
            int h = stoi(t[i].substr(0, 2)); // 시간 부분
            int m = stoi(t[i].substr(3, 2)); // 분 부분
            int time = h * 60 + m; // 각도가 같을 경우 시간으로 오름차순 해야함

            h %= 12; // 12로 나머지 연산을 하여 12시간 이내로 맞춤

            // 시계를 720등분
            int pos_h = h * 60 + m; // 시침의 위치는 (시간 * 60) + 분
            int pos_m = m * 12; // 분침의 위치는 (분 * 12)

            // 시침과 분침의 차이
            int diff = abs(pos_h - pos_m);
            int angle = min(diff, 720 - diff); // 각도는 180도보다 작아야 함

            v.push_back({ angle, { time, i } }); // 각도, 시간, 시간의 idx
        }

        sort(v.begin(), v.end());

        int ans_pos = v[2].second.second; // 정답 시간의 idx 추출
        cout << t[ans_pos] << "\n";
    }
}