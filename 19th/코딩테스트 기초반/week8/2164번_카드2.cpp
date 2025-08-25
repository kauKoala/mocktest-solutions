#include <iostream>
#include <queue>

using namespace std;

queue<int> q;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        q.push(i); // 모든 번호의 카드를 큐에 push
    }
    
    int ans;
    while (1) {
        // 제일 위에서 한 장 버림
        // 카드가 홀수 개수일 경우를 대비하여 ans에 저장
        ans = q.front(); 
        q.pop();
        if (q.empty()) break;
        
        // 제일 위의 카드를 제일 뒤로 보냄
        // 카드가 짝수 개수일 경우를 대비하여 ans에 저장
        ans = q.front();
        q.pop();
        if (q.empty()) break;
        q.push(ans);
        
    }
    
    cout << ans;
}