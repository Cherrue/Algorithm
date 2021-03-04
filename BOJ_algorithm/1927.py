"""
@TITLE : 최소 힙
@DATE : 2021-03-03
@URL : https://www.acmicpc.net/problem/1927
@TIME : 1sec
@MEMORY : 128MB
@SOLVE TIME : 15:51 ~ 16:09 // 18m
"""

import sys
import heapq

heap = []

n = int(sys.stdin.readline())

for i in range(0,n):
    temp = int(sys.stdin.readline())
    if temp==0:
        if len(heap)==0:
            print(0)
        else:
            sys.stdout.write(str(heapq.heappop(heap))+'\n')
    else:
        heapq.heappush(heap, temp)