#include <iostream>

using namespace std;

int main() {  
    int T;
    cin >> T;

    // * 참고 * 만약 벡터 or 배열에 대해 알고 계신다면 아래와 같이 모든 종족을 선언하실 필요가 없습니다.
    
    // 간달프 군대의 종족 선언
    int g_hobbit;
    int g_human;
    int g_elf;
    int g_dwarf;
    int g_eagle;
    int g_wizard;
    
    // 사우론 군대의 종족 선언
    int s_orc;
    int s_human;
    int s_warg;
    int s_goblin;
    int s_urukhai;
    int s_troll;
    int s_wizard;
    
    for (int i = 0; i < T; i++) { // T만큼 반복
        // 간달프 군대의 각 종족 입력
        cin >> g_hobbit >> g_human >> g_elf >> g_dwarf >> g_eagle >> g_wizard;
    
        // 간달프 군대의 각 종족 입력
        cin >> s_orc >> s_human >> s_warg >> s_goblin >> s_urukhai >> s_troll >> s_wizard;
        
        // 간달프 군대의 점수 계산
        int g_score = 1 * g_hobbit + 2 * g_human + 3 * g_elf + 3 * g_dwarf + 4 * g_eagle + 10 * g_wizard;
        
        // 사우론 군대의 점수 계산
        int s_score = 1 * s_orc + 2 * s_human + 2 * s_warg + 2 * s_goblin + 3 * s_urukhai + 5 * s_troll + 10 * s_wizard;
 
        // 전투 번호를 출력, i = 0부터 시작했기에 i + 1을 해주어 올바르게 출력
        cout << "Battle " << i + 1 << ": ";
        
        // 간달프 군대가 이길 경우
        if (g_score > s_score) cout << "Good triumphs over Evil";
        
        // 사우론 군대가 이길 경우
        else if (g_score < s_score) cout << "Evil eradicates all trace of Good";
        
        // 이기는 쪽이 없을 경우
        else cout << "No victor on this battle field";
        
        // 줄바꿈을 위해 출력
        cout << "\n";
    }
    
    return 0;
}