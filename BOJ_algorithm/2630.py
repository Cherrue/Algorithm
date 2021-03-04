"""
@TITLE : 색종이 만들기
@DATE : 2021-03-04
@URL : https://www.acmicpc.net/problem/2630
@TIME : 1sec
@MEMORY : 128MB
@SOLVE TIME : 20:09 ~ 20:46 // 37m
@TYPE : Divide and Conquer
"""
import sys

n = int(sys.stdin.readline())
paper = []
white_cnt = 0
blue_cnt = 0
for i in range(n):
    row =list(map(int, sys.stdin.readline().split()))
    paper.append(row)

def checkPaper(size, x, y):
    if size == 1:
        return paper[x][y]
    global white_cnt, blue_cnt
    half_size = int(size/2)
    left_top = checkPaper(half_size, x, y)
    right_top = checkPaper(half_size, x+half_size, y)
    left_bottom = checkPaper(half_size, x, y+half_size)
    right_bottom = checkPaper(half_size, x+half_size, y+half_size)

    add_all = left_top + left_bottom + right_top + right_bottom
    if add_all==4:
        return 1
    elif add_all==0:
        return 0
    else:
        blue_cnt += add_all%5
        white_cnt += (4-int(add_all/5)-add_all%5)
        return 5

last = checkPaper(n, 0, 0)
if last == 1:
    blue_cnt+=1
elif last == 0:
    white_cnt+=1

sys.stdout.write(str(white_cnt)+'\n'+str(blue_cnt))