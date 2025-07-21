#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> V[4];
vector<int> merged_V1;
vector<int> merged_V2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int a, b, c, d;
    for (int i = 0; i < N; i++) {
        cin >> a >> b >> c >> d;
        V[0].push_back(a);
        V[1].push_back(b);
        V[2].push_back(c);
        V[3].push_back(d);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            merged_V1.push_back(V[0][i] + V[1][j]); // 1번과 2번 더하여 저장 
            merged_V2.push_back(V[2][i] + V[3][j]); // 3번과 4번 더하여 저장
        }
    }

    sort(merged_V1.begin(), merged_V1.end());
    sort(merged_V2.begin(), merged_V2.end());

    // 투포인터
    // merged_V1에서는 작은 값부터
    // merged_V2에서는 큰 값부터
    int i = 0, j = merged_V2.size() - 1;
    long long ans = 0;
    while (1) {
        if (i >= merged_V1.size() || j < 0) break;
        int tmp_sum = merged_V1[i] + merged_V2[j];
        if (tmp_sum == 0) { 
            int tmp_value1 = merged_V1[i];
            int tmp_value2 = merged_V2[j];
            long long tmp_cnt1 = 0;
            long long tmp_cnt2 = 0;
            while (i < merged_V1.size() && tmp_value1 == merged_V1[i]) { // 중복 숫자 고려
                tmp_cnt1++;
                i++;
            }
            while (j >= 0 && tmp_value2 == merged_V2[j]) { // 중복 숫자 고려
                tmp_cnt2++;
                j--;
            }
            
            ans += tmp_cnt1 * tmp_cnt2;
        }
        else if (tmp_sum > 0) j--; // 큰 값을 줄임
        else i++; // 작은 값을 키움
    }

    cout << ans;
}