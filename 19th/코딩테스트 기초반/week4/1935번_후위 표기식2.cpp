#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int N;
    string str;
    stack<double> S;
    
    cin >> N;
    cin >> str; // 후위 표기식
    
    vector<double> num(N); // 크기 N으로 초기화
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
       
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') { // 피연산자일 경우 push  
            S.push(num[str[i] - 'A']);
        }
        else { // 연산자일 경우 stack의 상위 두 원소 pop
            double ans, tmp1, tmp2;
            tmp1 = S.top();
            S.pop();
            tmp2 = S.top();
            S.pop();

            // 먼저 나온 피연산자가 앞으로 오도록 함
            if (str[i] == '+') ans = tmp2 + tmp1; 
            if (str[i] == '-') ans = tmp2 - tmp1;
            if (str[i] == '*') ans = tmp2 * tmp1;
            if (str[i] == '/') ans = tmp2 / tmp1;

            S.push(ans);
        }     
    }
    
    // 소수점 2자리까지 표시하기 위함
    cout << fixed;
    cout.precision(2);
    
    cout << S.top();
}