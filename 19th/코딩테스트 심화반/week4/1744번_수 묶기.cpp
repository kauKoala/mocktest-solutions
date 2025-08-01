#include <iostream>
#include <queue>

using namespace std;

priority_queue<int, vector<int>, greater<int>> n_pq; // 0보다 작거나 같은 정수는 오름차순 저장
priority_queue<int> p_pq; // 0보다 큰 정수는 내림차순 저장

int main() {
    int N;
    cin >> N;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num <= 0) n_pq.push(num);
        else p_pq.push(num);
    }

    int ans = 0;

    // top에 위치한 두 원소를 곱하여 더하면 가장 큰 값이 됨
    // 만약 top에 한 원소만 있을 경우 그대로 더함
    int first, second; 
    while (!n_pq.empty()) {
        first = n_pq.top();
        n_pq.pop();
        if (n_pq.empty()) {
            ans += first;
            break;
        }
        second = n_pq.top();
        n_pq.pop();

        ans += first * second;
    }

    // top에 위치한 두 원소를 곱하여 더하면 가장 큰 값이 됨
    // 만약 top에 한 원소만 있을 경우 그대로 더함
    // 1의 경우 곱해도 크기가 커지지 않기에, 그대로 더함
    while (!p_pq.empty()) {
        first = p_pq.top();
        p_pq.pop();
        if (p_pq.empty()) {
            ans += first;
            break;
        }
        second = p_pq.top();
        p_pq.pop();

        if (first != 1 && second != 1) ans += first * second;
        else ans += first + second;
    }

    cout << ans;
}