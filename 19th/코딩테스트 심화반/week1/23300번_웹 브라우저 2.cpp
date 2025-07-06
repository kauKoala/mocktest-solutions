#include <iostream>
#include <stack>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;

    stack<int> backward_stack;
    stack<int> frontward_stack;

    char job;
    int num;
    int current_page = -1; // 초기 페이지

    for (int i = 0; i < Q; i++) {
        cin >> job;
        if (job == 'B') {
            if (!backward_stack.empty()) {
                if (backward_stack.top() == 0) {
                    // top이 페이지일 때 까지 pop
                    // 압축이 연속으로 N번 진행 됐을 경우 고려
                    while (!backward_stack.empty() && backward_stack.top() == 0) {
                        backward_stack.pop(); 
                    }

                    if (!backward_stack.empty()) { 
                        frontward_stack.push(current_page);
                        current_page = backward_stack.top();
                        
                        // 압축 수행, 압축이 중간에 들어가 있을 경우에도 추가로 pop
                        while (!backward_stack.empty() && (backward_stack.top() == current_page || backward_stack.top() == 0)) {
                            backward_stack.pop();
                        }
                    }

                    // 뒤로 가기 stack에서 pop되는 페이지에 한정하여 압축을 수행했기에 아직 pop 되지 않은 페이지를 위해 다시 0 삽입
                    backward_stack.push(0);
                }
                else {
                    frontward_stack.push(current_page); // 현재 페이지를 앞으로 가기 stack에 삽입
                    current_page = backward_stack.top(); // 현재 페이지 갱신
                    backward_stack.pop(); // 뒤로 가기 stack pop
                }
            }
        }
        if (job == 'F') {
            if (!frontward_stack.empty()) {
                backward_stack.push(current_page); // 현재 페이지를 뒤로 가기 stack에 삽입
                current_page = frontward_stack.top(); // 현재 페이지 갱신
                frontward_stack.pop(); // 앞으로 가기 stack pop
            }
        }
        if (job == 'A') {
            cin >> num;

            if (current_page != -1) backward_stack.push(current_page); // 현재 페이지가 있을 경우 뒤로 가기 stack에 삽입
            current_page = num; // 현재 페이지 갱신

            frontward_stack = stack<int>(); // 앞으로 가기 stack 초기화
        }
        if (job == 'C') {
            backward_stack.push(0); // 압축 시점을 알기 위해서 뒤로 가기 stack에 0 삽입
        }
    }

    bool is_compression = false; // 압축 여부
    bool is_exist = false; // 뒤로 가기 stack에 페이지가 존재하는지 확인

    cout << current_page << "\n";

    if (backward_stack.empty()) cout << -1 << "\n";
    else {
        while (!backward_stack.empty()) {
            if (backward_stack.top() == 0) {
                is_compression = true;
                backward_stack.pop();
                continue;
            }

            is_exist = true; // 뒤로 가기 stack에 페이지 존재
            if (is_compression) {
                int tmp = backward_stack.top();
                cout << tmp << " ";
                
                // 압축 수행, 압축이 중간에 들어가 있을 경우에도 추가로 pop
                while (!backward_stack.empty() && (backward_stack.top() == tmp || backward_stack.top() == 0)) {
                    backward_stack.pop();
                }
            }
            else {
                cout << backward_stack.top() << " ";
                backward_stack.pop();
            }
        }
        if (is_exist) cout << "\n";
        else cout << -1 << "\n";

    }

    if (frontward_stack.empty()) cout << -1;
    else {
        while (!frontward_stack.empty()) {
            cout << frontward_stack.top() << " ";
            frontward_stack.pop();
        }
    }

}