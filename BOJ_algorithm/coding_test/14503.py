import sys

n, m = map(int, sys.stdin.readline().split())
r, c, d = map(int, sys.stdin.readline().split())
arr_map = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
result = 0

dr, dc = (-1, 0, 1, 0), (0, 1, 0, -1)

while True:
    if arr_map[r][c] == 0:
        arr_map[r][c] = 2
        result += 1

    isFindWay = False
    for i in range(1, 5):
        if d == 0:
            d = 3
        else:
            d = d-1
        nr, nc = r+dr[d], c+dc[d]
        if nr >= n or nr < 0 or nc >= m or nc < 0:
            continue
        elif arr_map[nr][nc] == 0:
            r, c = nr, nc
            isFindWay = True
            break

    if isFindWay:
        continue

    r, c = r-dr[d], c-dc[d]
    if r >= n or r < 0 or c >= m or c < 0:
        break
    if arr_map[r][c] == 1:
        break

print(result)
