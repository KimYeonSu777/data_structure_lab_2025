from collections import deque                # Purpose: Deque 자료구조를 이용하여 BFS,DFS를 구현하기 위해 collections 모듈에서 deque 자료구조 import -> Deque을 이용하여 Queue(FIFO),Stack(LIFO) 구현이 목적.

A = {
    0: [1, 2, 3],
    1: [0, 2, 4, 5],
    2: [0, 1, 6],
    3: [0],
    4: [1],
    5: [1],
    6: [2]
}

def bfs(A):
    answer = []
    # TODO : BFS로 탐색하는 로직을 구현해주세요.          
    # 방문한 노드를 순서대로 answer 리스트에 넣어서 리턴해주세요.
    """
    그래프 A(인접 리스트)에서 BFS(너비 우선 탐색)를 수행하여
    시작 노드(0)로부터의 방문 순서를 리스트로 반환합니다.

    동작 방식:
    - 큐(queue)와 집합(visited)을 사용하여 중복 방문을 방지하며 탐색합니다.
    - 큐의 왼쪽에서 노드를 꺼내고, 인접 노드 중 아직 방문하지 않은 노드를 큐에 추가합니다.
    - 방문한 노드는 answer 리스트에 순서대로 저장합니다.
    - 탐색이 끝나면 answer 리스트를 반환합니다.

    Args(Arguments):
        A (dict): 그래프의 인접 리스트 표현. 각 노드의 번호를 key로, 인접 노드 리스트를 value로 가짐.

    Returns:
        list: BFS 탐색 순서대로 방문한 노드 번호의 리스트.
    """

    ''' <코드 line별 설명>
       line49: # Purpose: 이미 방문한 적이 있는 노드인지를 기록하기 위함. set()는 중복을 허용하지 않으므로, 노드의 중복 방문을 방지할 수 있음.
       line50: # Purpose: 큐(Queue) 자료구조를 구현하기 위해 queue 변수에 빈 deque 객체를 할당.
       line51: # Purpose: 탐색의 시작 노드(0)를 큐의 오른쪽 끝에 추가.
       line52: # Purpose: 0번 노드를 visited 집합에 추가하여 방문 표시.
       line54: # Purpose: queue에 데이터가 남아있는 동안 반복 수행(queue가 비면 False가 되어 반복 종료.)
       line55: # Purpose: 큐의 왼쪽(앞)에서 노드를 꺼내 node에 저장. BFS 개념을 적용하여 먼저 들어온 노드부터 처리.
       line56: # Purpose: 현재 방문한 노드를 answer 리스트에 저장. 방문 순서를 기록.(append()이므로 리스트 오르쪽 끝에서 차례로 추가됨)
       line57: # Purpose: 인접리스트 A를 참조하여 현재 노드의 인접정점(adjacent vertex)를 하나씩 검사하는 for문.
       line58: # Purpose: 아직 방문하지 않은 노드라면
       line59: # Purpose: 해당 노드를 visited 집합에 추가(방문 표시)
       line60: # Purpose: 해당 노드를 큐의 오른쪽(뒤)에 추가하여, 나중에 방문하도록 대기시킴.
       line62: # Purpose: BFS 탐색 순서가 담긴answer 리스트 반환.
  
    '''
    visited = set()                                                     
    queue = deque()                                                     
    queue.append(0)                                                      
    visited.add(0)                                                     

    while queue:                                                        
        node = queue.popleft()                                          
        answer.append(node)
        for neighbor in A[node]:                                        
            if neighbor not in visited:                                  
                visited.add(neighbor)                                    
                queue.append(neighbor)                                   
    print("Result of BFS: ", answer)
    return answer                                                      

def dfs(A):
    answer = []
    # TODO : DFS로 탐색하는 로직을 구현해주세요.
    # 방문한 노드를 순서대로 answer 리스트에 넣어서 리턴해주세요.
    
    """
    그래프 A(인접 리스트)에서 DFS(깊이 우선 탐색)를 수행하여
    시작 노드(0)로부터의 방문 순서를 리스트로 반환합니다.

    동작 방식:
    - 스택(stack)과 집합(visited)을 사용하여 중복 방문을 방지하며 탐색합니다.
    - 스택의 오른쪽 끝에서 노드를 꺼내고, 인접 노드 중 아직 방문하지 않은 노드를 스택에 추가합니다.
    - 더 작은 번호의 노드를 먼저 방문하기 위해 인접 노드를 reversed()로 역순 추가합니다.
    - 방문한 노드는 answer 리스트에 순서대로 저장합니다.
    - 탐색이 끝나면 answer 리스트를 반환합니다.

    Args(Arguments):
        A (dict): 그래프의 인접 리스트 표현. 각 노드의 번호를 key로, 인접 노드 리스트를 value로 가짐.

    Returns:
        list: DFS 탐색 순서대로 방문한 노드 번호의 리스트.
    """

    ''' <코드 line별 설명>
       line104: # Purpose: 이미 방문한 적이 있는 노드인지를 기록하기 위함.
       line105: # Purpose: 스택(Stack) 자료구조를 구현하기 위해 stack 변수에 빈 deque 객체를 할당
       line106: # Purpose: 시작 노드(0)를 스택의 오른쪽 끝에 추가.
       line107: # Purpose: 0번 노드를 visited 집합에 추가하여 방문 표시.
       line109: # Purpose: 스택에 데이터가 남아 있는 동안 반복. 스택이 비면 반복 종료.
       line110: # Purpose: 스택의 오른쪽 끝에서 노드를 꺼내 node에 저장. DFS 개념을 적용하여 가장 마지막에 추가된 노드부터 방문.
       line111: # Purpose: 현재 방문한 노드를 answer 리스트에 저장. 방문 순서를 기록.
       line112: # Purpose: 인접리스트 A를 참조하여 현재 노드의 인접정점(adjacent vertex)를 하나씩 검사하는 for문.
                           단, 문제에서는 더 작은 번호의 노드를 먼저 방문해야 하므로 reversed를 해야 stack을 적용했을 때 작은 번호의 노드를 먼저 방문하게 됨.
       line113: # Purpose: 아직 방문하지 않은 노드라면
       line114: # Purpose: 해당 노드를 스택의 왼쪽 앞에 추가.
       line115: # Purpose: 해당 노드를 visited 집합에 추가(방문 표시).
       line117: # Purpose: DFS 탐색 순서가 담긴 answer 리스트를 반환.
  
    '''
    
    visited = set()                                                     
    stack = deque()                                                      
    stack.append(0)                                                      
    visited.add(0)                                                       

    while stack:                                                         
        node = stack.pop()                                              
        answer.append(node)                                             
        for neighbor in reversed(A[node]):                                                                                                 
            if neighbor not in visited:                                  
                stack.append(neighbor)                                  
                visited.add(neighbor)                                   
    print("Result of DFS: ",answer)
    return answer                                                       

# 아래는 체크함수입니다. 수정하실 필요 없습니다.
bfs_result = bfs(A)
dfs_result = dfs(A)

assert bfs_result == [0,1,2,3,4,5,6]
assert dfs_result == [0,1,4,5,2,6,3]
print('PASSED!')
