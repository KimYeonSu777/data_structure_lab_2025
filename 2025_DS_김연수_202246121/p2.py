from collections import deque                  # Purpose: deque 자료구조를 사용하여 Stack을 구현하기 위해 import
import sys

## 입력 받는 코드입니다. 수정할 필요 없습니다.
sys.stdin = open('case.txt')
N, M = list(map(int,input().split()))
print(N, M)
concerts = []
for v in range(N):
    values = list(map(int, input().split()))
    concerts.append(values)
# print(concerts)
# [[1, 0, 0, 1, 1, 0], [1, 0, 1, 1, 0, 0], [1, 1, 1, 1, 0, 1], [0, 1, 1, 0, 1, 1], [0, 1, 0, 0, 1, 0]]
###################################


# Purpose: 콘서트장 약도(concerts)에서 독립된 무대 공간(0으로 연결된 영역)의 개수를 세는 함수.
#          콘서트 공간 전체를 탐색하여 0을 찾으면 DFS를 상하좌우로 모두 수행하여 수행한 DFS의 개수를 반환하는 함수.
def count_stages(concerts):

    """
    콘서트장 약도에서 독립된 무대 공간(0으로 연결된 영역)의 개수를 계산합니다.

    콘서트장은 0(빈 공간)과 1(펜스)로 이루어진 N x M 크기의 2차원 리스트로 주어집니다.
    DFS(깊이 우선 탐색)를 사용하여, 상하좌우로 연결된 0의 집합을 하나의 무대 공간으로 간주하고,
    전체 콘서트장 내 독립된 무대 공간의 총 개수를 반환합니다.

    Args(Arguments):
        concerts (list[list[int]]): 콘서트장의 상태를 나타내는 2차원 리스트.
            0은 무대 공간, 1은 펜스.

    Returns:
        int: 콘서트장 내 독립된 무대 공간(0으로 연결된 영역)의 개수.

    """
    
    ''' <line별 코드 설명>
    
    # line 61    : 각 위치의 방문 여부를 기록하는 2차원 배열 생성.
    # line 63,64 : 상하좌우 4방향 이동을 위한 가중치 값 정의.
    # line 66    : (x, y)에서 시작해서 연결된 모든 무대 공간(0)을 방문 처리하는 DFS 함수.
    # line 67    : deque을 이용하여 DFS에서 사용할 stack 생성.
    # line 68    : 시작 좌표를 스택에 추가.
    # line 69    : 시작 위치 방문 처리.
    # line 71    : Stack 자료구조가 빌 때까지 반복 수행
    # line 72    : 스택의 오른쪽(끝)에서 좌표를 꺼냄(LIFO).
    # line 73~75 : 상하좌우 4방향을 모두 탐색하는 반복문.
    # line 77,78 : 범위 내에 있고, 아직 방문하지 않았으며, 무대 공간(0)인 경우에만 이동.
    # line 79    : 스택에 새로운 좌표 추가(DFS 특성 유지).
    # line 80    : 방문 처리.
    # line 82~84 : 콘서트장 전체를 순회하며, 방문하지 않은 무대 공간(0)이 있으면 DFS(반복문)로 탐색 시작.
    # line 85    : 새로운 무대 공간이므로 DFS 반복문 탐색 시작.
    # line 86    : dfs 1회 실행 시 마다 answer를 증가시켜 독립된 무대 공간 개수 count.
    # line 88    : 최종적으로 계산된 무대 공간 개수를 반환.

    '''
    
    answer = 0
    # TODO : 콘서트 공간에서 무대의 개수를 계산해 반환해주는 함수를 작성해주세요.

    visited = [[False]*M for _ in range(N)] 

    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]

    def dfs(x, y):
        stack = deque()  
        stack.append((x, y))  
        visited[x][y] = True  

        while stack:
            cx, cy = stack.pop()  
            for dir in range(4):  
                nx = cx + dx[dir]
                ny = cy + dy[dir]
               
                if 0 <= nx < N and 0 <= ny < M:
                    if not visited[nx][ny] and concerts[nx][ny] == 0:
                        stack.append((nx, ny))  
                        visited[nx][ny] = True  

    for i in range(N):
        for j in range(M):
            if concerts[i][j] == 0 and not visited[i][j]:
                dfs(i, j)  
                answer += 1  

    return answer  

print(count_stages(concerts))
