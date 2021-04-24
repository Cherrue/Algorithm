import sys

n, m = map(int, sys.stdin.readline().split())

arr_map = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
visited = [[False]*m for _ in range(n)]
result = 64  # 8*8

safe = -3
virus = []
for i in range(n):
    for j in range(m):
        if arr_map[i][j] != 1:
            safe += 1
        if arr_map[i][j] == 2:
            virus.append((i, j))


def dfs(x, y):
    res = 1
    visited[x][y] = True
    for dx, dy in (1, 0), (-1, 0), (0, 1), (0, -1):
        nx, ny = x+dx, y+dy
        if nx >= n or nx < 0 or ny >= m or ny < 0:
            continue
        if not (visited[nx][ny] or arr_map[nx][ny]):
            res += dfs(nx, ny)
    return res


def solve(wall, x, y):
    global visited, result
    if wall == 3:
        cnt = 0
        visited = [[False]*m for _ in range(n)]
        for i, j in virus:
            cnt += dfs(i, j)
        result = min(result, cnt)
        return

    for i in range(x, n):
        if i == x:
            k = y
        else:
            k = 0
        for j in range(k, m):
            if arr_map[i][j] == 0:
                arr_map[i][j] = 1
                solve(wall+1, i, j+1)
                arr_map[i][j] = 0


solve(0, 0, 0)
print(safe-result)
