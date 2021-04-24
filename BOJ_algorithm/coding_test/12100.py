import sys
from collections import deque

n = int(sys.stdin.readline())
map1024 = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
q = deque()

result = 0


def getMapData(i, j):
    if map1024[i][j]:
        q.append(map1024[i][j])
        map1024[i][j] = 0


def mergeMap(i, j, dir_i, dir_j):
    while q:
        item = q.popleft()
        if map1024[i][j] == 0:
            map1024[i][j] = item
        elif item == map1024[i][j]:
            map1024[i][j] *= 2
            i, j = i + dir_i, j + dir_j
        else:
            i, j = i + dir_i, j + dir_j
            map1024[i][j] = item


def move(dir):
    global n
    if dir == 0:
        for i in range(n):
            for j in range(n):
                getMapData(i, j)
            mergeMap(i, 0, 0, 1)
    elif dir == 1:
        for j in range(n):
            for i in range(n):
                getMapData(i, j)
            mergeMap(0, j, 1, 0)
    elif dir == 2:
        for i in range(n):
            for j in range(n-1, -1, -1):
                getMapData(i, j)
            mergeMap(i, n-1, 0, -1)
    elif dir == 3:
        for j in range(n):
            for i in range(n-1, -1, -1):
                getMapData(i, j)
            mergeMap(n-1, j, -1, 0)


def dfs(loop_cnt):
    global n, result, map1024
    if loop_cnt == 5:
        for i in range(len(map1024)):
            result = max(result, max(map1024[i]))
        return

    remember_map = [_arg_row[:] for _arg_row in map1024]

    for dir in range(4):
        move(dir)
        dfs(loop_cnt+1)
        map1024 = [remember_row[:] for remember_row in remember_map]


dfs(0)
print(result)
