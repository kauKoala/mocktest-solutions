#include <iostream>

using namespace std;

// 전역 변수에 선언하면 모든 값이 0으로 초기화 됨
int map[501][501];

int main() {
    int N, M, B;
    
    cin >> N >> M >> B;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    
    int min_time = 1234567890; // 문제에서 나오지 않을 큰 수로 초기화
    int max_height = -1; // 문제에서 나오지 않을 작은 수로 초기화
    
    // 현재 높이 k를 0부터 256까지 설정하며 해당 높이로 블록을 쌓거나 제거하는데 걸리는 시간을 구함
    // 가장 시간이 짧고, 땅의 높이가 높은 선택지를 선택
    for (int k = 0; k <= 256; k++) {
        // 좌표 (i, j)의 가장 위에 있는 블록을 제거하여 인벤토리에 넣는 작업
        int job_one_cnt = 0; 
        // 인벤토리에서 블록 하나를 꺼내어 좌표 (i, j)의 가장 위에 있는 블록 위에 놓는 작업
        int job_two_cnt = 0;
        
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // 현재 높이 k보다 높을 경우
                // 블록을 현재 높이 k로 맞추기 위해 map[i][j] - k만큼 1번 작업 수행
                if (k < map[i][j]) job_one_cnt += map[i][j] - k; 

                // 현재 높이 k보다 낮을 겨우
                // 블록을 현재 높이 k로 맞추기 위해 k - map[i][j]만큼 2번 작업 수행
                else if (k > map[i][j]) job_two_cnt += k - map[i][j];
            }
        }
        
        // 초기 블록 개수 + 1번 작업을 통해 얻은 블록의 개수가 사용한 블록의 개수보다 같거나 많아야 가능
        if (B + job_one_cnt - job_two_cnt >= 0) { 
            
            // 1번 작업 * 2 + 2번 작업의 시간이 현재 최소 시간보다 작거나 같은 경우
            if (min_time >= job_one_cnt * 2 + job_two_cnt) {
                // 최소 시간 갱신
                min_time = job_one_cnt * 2 + job_two_cnt;
                // 최대 높이 갱신
                max_height = k;
            }
        }
    }
    
    cout << min_time << " " << max_height;
}