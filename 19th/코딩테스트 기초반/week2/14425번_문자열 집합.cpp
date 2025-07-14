#include <iostream>
#include <string>
#include <set> // set을 사용하기 위함

using namespace std;

int main() {
    int N, M;
    string str;
    set<string> S_set;
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> str;
        S_set.insert(str); // 입력받은 문자열을 set에 저장    
    }
    
    int cnt = 0;
    for (int i = 0; i < M; i++) {
        cin >> str;
        
        // 입력받은 str을 set에서 조회
        // 찾지 못했을 경우 end()와 같아짐
        // 찾았을 경우 cnt = cnt + 1
        if (S_set.find(str) != S_set.end()) cnt++;
    }
    
    cout << cnt;
}