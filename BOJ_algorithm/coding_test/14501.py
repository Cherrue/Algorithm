import sys

n = int(sys.stdin.readline())

arr_work = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]

arr_stacked = [0]*(21)  # n=15 t=5

for i in range(n-1, -1, -1):
    t, m = arr_work[i][0], arr_work[i][1]
    if i+t > n:
        arr_stacked[i] = arr_stacked[i+1]
    elif arr_stacked[i+1] < arr_stacked[i+t] + m:
        arr_stacked[i] = arr_stacked[i+t] + m
    else:
        arr_stacked[i] = arr_stacked[i+1]
print(arr_stacked[0])
