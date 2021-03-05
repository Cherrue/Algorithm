"""
@TITLE : 최대 힙
@DATE : 2021-03-05
@URL : https://www.acmicpc.net/problem/11279
@TIME : 1sec
@MEMORY : 256MB
@SOLVE TIME : 20:11 ~ 20:48 // 37m
@TYPE : 자료구조
"""
import sys

heap = [0]
heap_size = 0

for i in range(int(sys.stdin.readline())):
    oper = int(sys.stdin.readline())
    if oper:
        heap_size += 1
        if len(heap) == heap_size:
            heap.append(oper)
        else:
            heap[heap_size] = oper
        idx = heap_size
        while idx>1:
            if heap[idx] > heap[idx//2]:
                temp = heap[idx]
                heap[idx] = heap[idx//2]
                heap[idx//2] = temp
                idx = idx//2
            else:
                break
    else:
        if heap_size:
            sys.stdout.write(str(heap[1])+'\n')
            heap[1] = heap[heap_size]
            heap[heap_size] = 0
            heap_size -= 1
            idx = 1
            while idx < heap_size:
                left_idx = 0 if idx*2 > heap_size else idx*2
                right_idx = 0 if idx*2+1 > heap_size else idx*2+1

                if heap[left_idx] > heap[right_idx]:
                    next_idx = left_idx
                else:
                    next_idx = right_idx

                if heap[next_idx] < heap[idx]:
                    break
                temp = heap[next_idx]
                heap[next_idx] = heap[idx]
                heap[idx] = temp

                idx = next_idx

        else:
            sys.stdout.write('0'+'\n')
