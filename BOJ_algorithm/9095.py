"""
@TITLE : 1,2,3 더하기
@DATE : 2021-03-05
@URL : https://www.acmicpc.net/problem/9095
@TIME : 1sec
@MEMORY : 512MB
@SOLVE TIME : 19:33 ~ 20:10 // 43m
@TYPE : dp
"""
import sys

arr = [0, 1, 2, 4]
for i in range(4, 12):
    arr.append(arr[i-1] + arr[i-2] + arr[i-3])

for i in range(int(sys.stdin.readline())):
    sys.stdout.write(str(arr[int(sys.stdin.readline())])+'\n')
