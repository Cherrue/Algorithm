import sys

n, m, x, y, k = map(int, sys.stdin.readline().split())
arr_map = []
for _ in range(n):
    arr_map.append(list(map(int, sys.stdin.readline().split())))
move = list(map(int, sys.stdin.readline().split()))


dice = [0, 0, 0, 0, 0, 0]


def rollDice(dir):
    global dice
    temp_dice = [0, 0, 0, 0, 0, 0]
    if dir == 1:  # east
        temp_dice[0] = dice[3]
        temp_dice[2] = dice[0]
        temp_dice[3] = dice[5]
        temp_dice[5] = dice[2]

        temp_dice[1] = dice[1]
        temp_dice[4] = dice[4]
    elif dir == 2:  # west
        temp_dice[0] = dice[2]
        temp_dice[2] = dice[5]
        temp_dice[3] = dice[0]
        temp_dice[5] = dice[3]

        temp_dice[1] = dice[1]
        temp_dice[4] = dice[4]
    elif dir == 3:  # north
        temp_dice[0] = dice[4]
        temp_dice[1] = dice[0]
        temp_dice[4] = dice[5]
        temp_dice[5] = dice[1]

        temp_dice[2] = dice[2]
        temp_dice[3] = dice[3]
    elif dir == 4:  # south
        temp_dice[0] = dice[1]
        temp_dice[1] = dice[5]
        temp_dice[4] = dice[0]
        temp_dice[5] = dice[4]

        temp_dice[2] = dice[2]
        temp_dice[3] = dice[3]
    dice = temp_dice[:]


dir_x = (0, 0, 0, -1, 1)
dir_y = (0, 1, -1, 0, 0)
for i in range(k):
    d = move[i]
    x, y = x + dir_x[d], y + dir_y[d]
    if x >= n or x < 0 or y >= m or y < 0:
        x, y = x - dir_x[d], y - dir_y[d]
        continue

    rollDice(d)

    if arr_map[x][y] == 0:
        arr_map[x][y] = dice[5]
    else:
        dice[5] = arr_map[x][y]
        arr_map[x][y] = 0
    print(dice[0])
