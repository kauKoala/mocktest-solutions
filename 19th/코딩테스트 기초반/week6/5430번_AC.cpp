#include <iostream>
#include <deque>
#include <string>

using namespace std;

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        string S;
        int n;
        string input_array;

        cin >> S;
        cin >> n;
        cin >> input_array;

        deque<int> dq;
        bool reverse = false;
        bool possible = true;
        string tmp = "";
        for (int i = 1; i < input_array.size() - 1; i++) {
            if (input_array[i] != ',') {
                tmp += input_array[i]; // 숫자만 저장
            }
            else {
                dq.push_back(stoi(tmp)); // stoi를 사용하여 string을 int로 바꾸어 저장
                tmp = "";
            }
        }
        if (tmp != "") dq.push_back(stoi(tmp));

        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 'R') {
                reverse = !reverse; // reverse의 상태를 현재와 반대로 저장(true -> false or false -> true)
            }
            if (S[i] == 'D') {
                if (dq.empty()) { // deque가 비어있다면 error
                    possible = false;
                    cout << "error" << "\n";
                    break;
                }
                else { 
                    if (reverse) { // 현재 뒤집힌 상태일 경우 뒤에서 삭제
                        dq.pop_back();
                    }
                    else { // 아닐 경우 앞에서 삭제
                        dq.pop_front();
                    }
                }
            }
        }

        if (possible) { // 모든 함수가 정상적으로 작동했을 경우
            cout << "[";
            if (reverse) { // 현재 뒤집힌 상태일 경우 뒤에서부터 출력
                while (!dq.empty()) {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty()) cout << ",";
                }
            }
            else { // 아닐 경우 앞에서부터 출력
                while (!dq.empty()) {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty()) cout << ",";

                }
            }
            cout << "]" << "\n";
        }

    }
}