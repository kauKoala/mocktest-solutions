 #include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int time = 30; // 30분으로 설정
    int ans = 0; // 정답 초기화
    int T; // 챕터를 공부하는데 걸리는 시간
    for (int i = 0; i < N; i++) {
        if (time == 0) time = 30; // 만약 휴식 중이었다면 다시 공부 시작
        
        cin >> T;
        
        // 조건문, 만약 T가 현재 시간보다 작다면 챕터 전체 공부 가능
        if (T <= time) { 
            // 전체(절반 이상)를 공부했으므로 정답에 추가
            ans++; 
            
            // 다음 챕터를 바로 시작해야 하기에 남은 시간을 표시하기 위해 현재 time에서 챕터 공부 시간을 뺀다.
            time -= T; // time = time - T와 같다.
        }
        // 만약 T가 현재 시간보다는 크고 2 * 현재 시간보다는 작을 경우 절반 이상 공부 가능
        else if (T <= 2 * time) {
            // 절반 이상 공부했으므로 정답에 추가
            ans++;
            
            // T가 현재 time보다 크기에 휴식
            time = 0;
        } 
        // 만약 T가 2 * 현재 시간보다도 클 경우 절반 이상도 공부하지 못한 챕터가 된다.
        // T가 현재 time보다 크기에 휴식
        else time = 0;
    }
    
    cout << ans;
    
    return 0;
}