"""
@TITLE : 토마토
@DATE : 2021-03-04
@URL : https://www.acmicpc.net/problem/7576
@TIME : 1sec
@MEMORY : 256MB
@SOLVE TIME : 20:55 ~ 21:34 // 39m
@TYPE : BFS
"""
import sys
from collections import deque

m, n = map(int, sys.stdin.readline().split())
arr = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

bfs = deque([(i,j) for i in range(n) for j in range(m) if arr[i][j] == 1])

mute = False
day = -1

while not mute:
    for i in range(len(bfs)):
        idx = bfs.popleft()

        if idx[0] < n-1 and arr[idx[0]+1][idx[1]] == 0:
            arr[idx[0]+1][idx[1]] = 1
            bfs.append((idx[0]+1, idx[1]))
        
        if idx[0] > 0 and arr[idx[0]-1][idx[1]] == 0:
            arr[idx[0]-1][idx[1]] = 1
            bfs.append((idx[0]-1, idx[1]))
        
        if idx[1] < m-1 and arr[idx[0]][idx[1]+1] == 0:
            arr[idx[0]][idx[1]+1] = 1
            bfs.append((idx[0], idx[1]+1))
        
        if idx[1] > 0 and arr[idx[0]][idx[1]-1] == 0:
            arr[idx[0]][idx[1]-1] = 1
            bfs.append((idx[0], idx[1]-1))

    day += 1

    if len(bfs) == 0:
        mute = True

for i in range(n):
    for j in range(m):
        if arr[i][j] == 0:
            sys.stdout.write('-1')
            exit()

sys.stdout.write(str(day))