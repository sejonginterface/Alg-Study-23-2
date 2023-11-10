import sys
import heapq
from bisect import bisect_left, bisect_right
from collections import deque, Counter
from itertools import permutations, product, combinations, combinations_with_replacement
import math

dq = deque() # 노드 저장할 덱
visited = [False for _ in range(1001)] # 방분 배열 
adj = [ [0 for _ in range(1001)] for _ in range(1001)] # 인접 행렬

N, M, V = 0,0,0

N, M, V = map(int, sys.stdin.readline().split())

for i in range(M):
	v, w = map(int, sys.stdin.readline().split())
	adj[v][w] = 1
	adj[w][v] = 1
 
for i in range(1,N+1):
    for j in range(1,N+1):
        print(adj[i][j], end=" ")
    print()


dq.append( (V, 0) ) # dq에 V 추가 # ( 노드, 레벨 )
visited[V] = True


while (dq): # 처음들어갈 때는 V가 있는 상태
    curr = dq.popleft() # 처음에는 지금 V가 되고 # 현재 위치 갱신
    
    print(curr, end=" ") ## if ( curr == target) break ## 이부분이 종료조건 확인
    
    for i in range(1, N+1):
        if (adj[curr[0]][i] == 1 and visited[i] == False): ## 유효 조건 확인 ## 기타 valid 전부 이곳에 추가
            dq.append( (i, curr[1] + 1) ) ## dq에 다음 레벨 추가 # 이조건이 결국 거리측정
            visited[i] = True
            #print(dq)
    