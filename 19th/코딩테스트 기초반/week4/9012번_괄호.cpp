#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int T;
    string str;
    
    cin >> T;
    
    while(T--) {
        bool VPS = true;
        stack<char> S;
        cin >> str;
        
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '(') S.push(str[i]); // '(' 모양이면 스택에 push
            else if (str[i] == ')' && !S.empty()) S.pop(); // ')' 모양이고, 내부에 '(' 모양이 존재하면 스택에서 pop
            else if (str[i] == ')' && S.empty()) { // ')' 모양인데, 스택에 아무런 값도 없을 경우 VPS가 아님
                VPS = false;
                break;
            }
        }
        
        if (VPS && S.empty()) cout << "YES" << "\n"; // VPS가 true이고, 스택이 모두 비어있다면 해당 문자열은 VPS
        else cout << "NO" << "\n";

    }
}