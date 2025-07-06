#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    int N;
    cin >> N;
    
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        pq.push(num);
    }
    
    if (N == 1) cout << 0;
    else {
        int a, b;
        int ans = 0;
        
        // 작은 두 수부터 더하기
        while (1) {
            a = pq.top();
            pq.pop();
            b = pq.top();
            pq.pop();
            ans += a + b;
            if (pq.empty()) break;
        
            pq.push(a + b);
        }
    
        cout << ans;
    } 
}