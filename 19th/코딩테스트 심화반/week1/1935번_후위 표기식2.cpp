#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int N;
    string str;
    stack<double> S;
    
    cin >> N;
    cin >> str; // 후위 표기식
    
    double num[26];
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }
       
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {         
            S.push(num[str[i] - 'A']);
        }
        else {
            double ans, tmp1, tmp2;
            if (str[i] == '+') {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                ans = tmp2 + tmp1;                
            }
            if (str[i] == '-') {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                ans = tmp2 - tmp1;
            }
            if (str[i] == '*') {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                ans = tmp2 * tmp1;
            }
            if (str[i] == '/') {
                tmp1 = S.top();
                S.pop();
                tmp2 = S.top();
                S.pop();
                ans = tmp2 / tmp1;
            }
            S.push(ans);
        }     
    }
    
    // 소수점 2자리까지 표시하기 위함
    cout << fixed;
    cout.precision(2);
    
    cout << S.top();
}