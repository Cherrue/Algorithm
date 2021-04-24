import sys
from collections import deque

n = int(input())
arr_map = [[0]*n for _ in range(n)]
q_move = list()
q_status = deque()


k = int(input())
for i in range(k):
    y, x = map(int, sys.stdin.readline().split())
    arr_map[y-1][x-1] = 1

l = int(input())
for i in range(l):
    t, dir = sys.stdin.readline().split()
    q_move.append((int(t), dir))

dx = (1, -1, 0, 0)
dy = (0, 0, 1, -1)
L = (3, 2, 0, 1)
D = (2, 3, 1, 0)
now, x, y, d, move_idx = 0, 0, 0, 0, 0
arr_map[0][0] = 2
q_status.append((0, 0))
while True:
    x, y = x+dx[d], y+dy[d]
    now += 1
    if x >= n or x < 0 or y >= n or y < 0 or arr_map[y][x] == 2:
        break
    if not arr_map[y][x]:
        last_x, last_y = q_status.popleft()
        arr_map[last_y][last_x] = 0
    arr_map[y][x] = 2
    q_status.append((x, y))
    if move_idx < l and q_move[move_idx][0] == now:
        if q_move[move_idx][1] == 'L':
            d = L[d]
        else:
            d = D[d]
        move_idx += 1

print(now)
