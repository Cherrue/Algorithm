import sys

n = int(sys.stdin.readline())
list_test = list(map(int, sys.stdin.readline().split()))
b, c = map(int, sys.stdin.readline().split())
result = n
for i in range(n):
    if (list_test[i] - b) / c > 0:
        result += (list_test[i] - b) // c
        if (list_test[i] - b) % c > 0:
            result += 1

print(result)
