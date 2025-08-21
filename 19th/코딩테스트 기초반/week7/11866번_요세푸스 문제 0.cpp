#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    queue<int> Q;
    vector<int> V;

    int N, K;

    cin >> N >> K;

    for (int i = 1; i <= N; i++) Q.push(i);

    int cnt = 0;
    int tmp;
    // 큐의 front에 위치하는 원소를 하나씩 확인하고 back에 넣는 작업을 함
    // 큐의 원소를 탐색할 때 마다 cnt를 1씩 늘림
    // cnt가 K와 같아지면 해당 원소를 벡터에 저장하고, cnt를 초기화함
    while (!Q.empty()) {
        cnt++;
        tmp = Q.front();
        Q.pop();

        if (cnt == K) { 
            cnt = 0;
            V.push_back(tmp);
        }
        else Q.push(tmp);
    }

    for (int i = 0; i < V.size(); i++) {
        if (i == 0) cout << "<";

        cout << V[i];
        if (i == V.size() - 1) cout << ">";
        else cout << ", ";
    }
}