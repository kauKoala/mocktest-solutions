#include <iostream>

using namespace std;

// 전역 변수에 선언하면 모든 값이 false로 초기화 됨
bool no_self_num[10001]; 

int main() {
    for (int i = 1; i <= 10000; i++) {
        int num = i;
        int sum = num;
        
        // num이 0이 아니라면 반복문 실행
        while (num) { 
            sum += num % 10; // num을 10으로 나눈 나머지, 즉 현재 num의 일의 자리 수
            num /= 10; // num을 10으로 나눈 몫
        }
        
        // sum이 10000 이하일 경우
        if (sum <= 10000) {
           no_self_num[sum] = true; 
        }
    }
    
    for (int i = 1; i <= 10000; i++) {
        // self_num인 값들만 출력
        if (no_self_num[i] == false) cout << i << "\n";
    }
}