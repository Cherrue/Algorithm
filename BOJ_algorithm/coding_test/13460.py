import sys
from collections import deque

h, w = map(int, sys.stdin.readline().split())

arr_map = [list(sys.stdin.readline())[:-1] for _ in range(h)]
visited = [[[[0]*11 for _ in range(11)] for _ in range(11)] for _ in range(11)]

R_x = -1
R_y = -1
B_x = -1
B_y = -1
for i in range(h):
    for j in range(w):
        if arr_map[i][j] == 'R':
            R_x = j
            R_y = i
        elif arr_map[i][j] == 'B':
            B_x = j
            B_y = i

    if R_x != -1 and B_x != -1:
        break

bfs = deque()
bfs.append((R_x, R_y, B_x, B_y, 0))
dir_x = [-1, 1, 0, 0]
dir_y = [0, 0, -1, 1]
result = -1
while bfs:
    current_info = bfs.popleft()

    if current_info[4] > 10:
        break
    if arr_map[current_info[1]][current_info[0]] == 'O' and arr_map[current_info[3]][current_info[2]] != 'O':
        result = current_info[4]
        break

    for dir_i in range(4):
        next_R_x = current_info[0]
        next_R_y = current_info[1]
        next_B_x = current_info[2]
        next_B_y = current_info[3]
        while True:
            if arr_map[next_R_y][next_R_x] != '#' and arr_map[next_R_y][next_R_x] != 'O':
                next_R_x += dir_x[dir_i]
                next_R_y += dir_y[dir_i]
            else:
                if arr_map[next_R_y][next_R_x] == '#':
                    next_R_x -= dir_x[dir_i]
                    next_R_y -= dir_y[dir_i]
                break

        while True:
            if arr_map[next_B_y][next_B_x] != '#' and arr_map[next_B_y][next_B_x] != 'O':
                next_B_x += dir_x[dir_i]
                next_B_y += dir_y[dir_i]
            else:
                if arr_map[next_B_y][next_B_x] == '#':
                    next_B_x -= dir_x[dir_i]
                    next_B_y -= dir_y[dir_i]
                break

        if next_B_y == next_R_y and next_R_x == next_B_x and arr_map[next_R_y][next_R_x] != 'O':
            R_dist = abs(current_info[0] - next_R_x) + \
                abs(current_info[1] - next_R_y)
            B_dist = abs(current_info[2] - next_B_x) + \
                abs(current_info[3] - next_B_y)
            if R_dist > B_dist:
                next_R_x -= dir_x[dir_i]
                next_R_y -= dir_y[dir_i]
            else:
                next_B_x -= dir_x[dir_i]
                next_B_y -= dir_y[dir_i]

        if visited[next_R_x][next_R_y][next_B_x][next_B_y] == 0:
            visited[next_R_x][next_R_y][next_B_x][next_B_y] = 1
            bfs.append([next_R_x, next_R_y, next_B_x,
                        next_B_y, current_info[4]+1])

print(result)
