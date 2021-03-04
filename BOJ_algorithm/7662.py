"""
@TITLE : 이중 우선순위 큐
@DATE : 2021-03-04
@URL : https://www.acmicpc.net/problem/7662
@TIME : 6sec
@MEMORY : 256MB
@SOLVE TIME : 21:42
@TYPE : 
"""
import sys
from collections import deque

class Node(object):
    def __init__(self, data):
        self.data = data
        self.left = self.right = None

class BST(object):
    def __init__(self):
        self.root = None

    def insert(data):
        

for i in int(sys.stdin.readline():
    arr_size = 0
    for j in int(sys.stdin.readline():
        operation, num = sys.stdin.readline().split()
        if operation == 'I':
            idx = 1
            data = int(num)
            binary_search.append(0)
            while True:
                if binary_search[idx] == 0:
                    binary_search[idx] = data
                    break
                
                if data > 
                binary_search[idx] = binary_search[idx//2]
                binary_search[idx//2] = binary_search[idx]
        else:
            delete(binary_search, -1)
    if arr_size == 0:
        sys.stdout.write('EMPTY')
    else:
        min = min(binary_search)
        max = max(binary_search)
        sys.stdout.write(str(max) + ' ' str(min))