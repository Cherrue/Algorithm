import sys

n, m = map(int, sys.stdin.readline().split())

arr_map = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

dx = [1, -1, 0, 0, 1, 1, -1, -1]
dy = [0, 0, 1, -1, 1, -1, 1, -1]

tetrimino = [
    # I
    (0, 0, 0),
    (2, 2, 2),
    # O
    (0, 2, 1),
    # L
    (2, 2, 0),
    (0, 0, 3),
    (0, 2, 2),
    (2, 5, 0),
    # J
    (2, 2, 1),
    (0, 0, 2),
    (0, 6, 2),
    (2, 0, 0),
    # S
    (0, 3, 0),
    (2, 0, 2),
    # Z
    (0, 2, 0),
    (2, 1, 2),
    # T
    (4, 3, 0),
    (4, 1, 2),
    (5, 2, 0),
    (7, 0, 3),
]
max_sum = arr_map[0][0]+arr_map[0][1]+arr_map[0][2]+arr_map[0][3]
for i in range(n):
    for j in range(m):
        for k in range(len(tetrimino)):
            sum_tetrimino = arr_map[i][j]
            x, y = j, i
            for tet in range(3):
                x, y = x + dx[tetrimino[k][tet]], y + dy[tetrimino[k][tet]]
                if x >= m or x < 0 or y >= n or y < 0:
                    # if x >= m or x < 0 or y >= n or y < 0:
                    sum_tetrimino = arr_map[0][0] + \
                        arr_map[0][1]+arr_map[0][2]+arr_map[0][3]
                    break
                sum_tetrimino += arr_map[y][x]
            if max_sum < sum_tetrimino:
                max_sum = sum_tetrimino

print(max_sum)
