from collections import defaultdict

n = int(input())

# 부모-자식 관계를 저장할 딕셔너리 (부모: 자식 리스트)
adj = defaultdict(list)

for i in range(n-1):
    c, p = input().split()
    adj[p].append(c)  # 부모에 자식 추가

# DFS 함수: 현재 노드에서 목표 노드(ans)가 있는지 탐색
def dfs(node, ans):
    if node == ans:  # 현재 노드가 목표라면
        return True

    for i in adj[node]:  # 현재 노드의 모든 자식 탐색
        if dfs(i, ans):  # 자식 노드에서 목표 찾으면 True 반환
            return True
        
    return False  # 목표 노드 못 찾으면 False

c1, c2 = input().split()  # 관계를 확인할 두 사람 입력

# c1이 c2의 조상인지, 또는 c2가 c1의 조상인지 확인
if dfs(c1, c2) or dfs(c2, c1):
    print(1)
else:
    print(0)