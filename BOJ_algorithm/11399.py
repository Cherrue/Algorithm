"""
@TITLE : ATM
@DATE : 2021-03-05
@URL : https://www.acmicpc.net/problem/11399
@TIME : 1sec
@MEMORY : 256MB
@SOLVE TIME : 22:53 ~ 21:01 // 8m
@TYPE : 
"""
import sys

#for i in range(int(sys.stdin.readline())):
n = int(sys.stdin.readline())
arr = list(map(int, sys.stdin.readline().split()))
sum = 0
arr.sort()
for i in range(len(arr)):
    sum += arr[i]*(len(arr)-i)

print(sum)