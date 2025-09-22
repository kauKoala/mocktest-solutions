#include <iostream>
#include <string> // string을 사용하기 위해 string 헤더 파일 include

using namespace std;

int main() {
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;
    
    int pos = pattern.find('*'); // find는 문자열에서 특정 문자 or 문자열을 찾는 함수
    
    // * 모양 왼쪽의 string 저장
    // substr(a, b)는 인덱스 a부터 b - 1까지의 문자열을 저장하는 함수
    string pattern_first = pattern.substr(0, pos); 
    
    // * 모양 오른쪽의 string 저장
    // substr(a, b)는 인덱스 a부터 b - 1까지의 문자열을 저장하는 함수
    // length는 문자열의 길이를 반환하는 함수
    string pattern_last = pattern.substr(pos + 1, pattern.length()); 
    
    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        
        // 만약 str의 문자열 길이보다 패턴의 길이가 더 길 경우 NE 출력
        if (pattern_first.length() + pattern_last.length() > str.length()) {
            cout << "NE" << endl;
            
            // 반복문에서 이번 루프를 건너뛰고 바로 다음으로 넘어갈 수 있게 하는 제어문
            // continue가 실행되면 다음 코드가 실행되는 것이 아니라 다음 반복으로 넘어간다.
            // for문에 의해 i++가 실행되고 string str 부분으로 가게 된다.
            continue; 
        } 

        // pattern_first의 길이만큼 앞에서부터 추출
        string str_first = str.substr(0, pattern_first.length());
        
        // pattern_last의 길이만큼 뒤에서부터 추출
        string str_last = str.substr(str.length() - pattern_last.length(), str.length());
        
        // 입력받은 str과 pattern이 일치하면 DA 출력
        if (pattern_first == str_first && pattern_last == str_last) cout << "DA" << endl;
        // 일치하지 않을 경우 NE 출력
        else cout << "NE" << endl;
    }
    
    return 0;
}