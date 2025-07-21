#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    int n;
    string S;
    map<string, int, greater<string>> M; // greater이용하여 내림차순 정렬 
    
    cin >> n;

    // 이전 입력의 개행 문자('\n')를 제거
    // getline이 빈 문자열을 읽지 않도록 하기 위함
    cin.ignore(); 
    
    while (n--) {
        // 개행 문자('\n')가 나올 때 까지 입력을 받음음
        // 즉 한 줄 전체를 입력 받음 ex) S == Baha enter
        getline(cin, S); 
        
        // 입력 받은 string을 이름과 로그로 분리
        string name = "", log = "";
        bool space = false;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] == ' ') space = true;
            else if (!space) name += S[i]; // 스페이스바가 없었다면 이름
            else log += S[i]; // 스페이스바가 있었다면 로그
        }
        
        if (log == "enter") M[name]++; // 로그가 enter라면 map에 1 추가
        else M[name]--; // 로그가 leave라면 map에 1 제거
    }
    
    for (auto i : M) {
        if (i.second == 1) cout << i.first << "\n";
    }
}