"""
@TITLE : 바이러스
@DATE : 2021-03-03
@URL : https://www.acmicpc.net/problem/2606
@TIME : 1sec
@MEMORY : 128MB
@SOLVE TIME : 17:09 ~ 17:55 // 46m , python setting complete
"""
import sys
from collections import deque

n = int(sys.stdin.readline())
m = int(sys.stdin.readline())

stack = deque()
adj_matrix = [[0 for _ in range(n+1)] for _ in range(n+1)]

for i in range(m):
    a, b = map(int, sys.stdin.readline().split())
    adj_matrix[a][b] = 1
    adj_matrix[b][a] = 1

visited = [0 for _ in range(n+1)]
visited[1] = 1

stack.append(1)
visited[1] = 1
cnt = -1

while(stack):
    node = stack.pop()
    cnt += 1
    for i in range(1, n+1):
        if adj_matrix[node][i] == 1 and visited[i] == 0:
            visited[i] = 1
            stack.append(i)

sys.stdout.write(str(cnt))