#include <iostream>
#include <vector>

using namespace std;

vector<int> V;

int main() {
    int N, K;
    
    cin >> N >> K;
    
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num == 1) V.push_back(i); // 라이언 인형인 인덱스를 저장
    }
    
    if (V.size() < K) cout << -1;
    else {
        int min_value = 1000001;
        
        int i = 0;
        int j = K - 1;
        while (1) {
            if (j >= V.size()) break;
            
            min_value = min(min_value, V[j] - V[i] + 1);
            
            i++;
            j++;
        }
        
        cout << min_value;
    }
}