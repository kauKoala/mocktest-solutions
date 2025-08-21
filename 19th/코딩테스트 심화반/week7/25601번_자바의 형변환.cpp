#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, string> hash_map;

bool possible = false;

void dfs(string s1, string s2) {
    if (possible) return;

    auto n = hash_map.find(s1); // s1을 키로 갖는 value가 있는지 확인
    if (n != hash_map.end()) { // value가 존재할 경우
        if (n->second == s2) possible = true;
        else dfs(n->second, s2);
    }
}

int main() {
    // 빠른 입출력
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    // 둘 다 string이기에 unordered_map에 저장
    // 자식에서 부모로만 갈 수 있게끔 단방향으로 저장
    string child, parent;
    for (int i = 0; i < N - 1; i++) {
        cin >> child >> parent;

        hash_map[child] = parent;
    }

    string s1, s2;
    cin >> s1 >> s2;

    // 자식 클래스에서 시작하여 부모 클래스를 찾는 경우만 찾기 위해 dfs 두 번 수행
    dfs(s1, s2);
    dfs(s2, s1);

    if (possible) cout << 1;
    else cout << 0;
}