#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    // 빠른 입출력
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> A(N); // 수열 저장
    vector<int> ans(N, -1); // 각 원소의 오큰수를 저장, 오큰수가 없으면 -1이기에 -1로 초기화 
    stack<int> s;  // 수열의 인덱스 저장

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < N; i++) {
        // 스택이 비어있지 않고, 현재 스택 top 원소보다 큰 원소가 나왔을 경우
        while (!s.empty() && A[s.top()] < A[i]) { 
            ans[s.top()] = A[i]; // 현재 스택 top 원소의 오큰수가 A[i]가 됨
            s.pop();
        }
        s.push(i); // 현재 원소의 인덱스를 push
    }

    for (int i = 0; i < N; i++) cout << ans[i] << " "; // 정답을 인덱스 순서대로 출력
}