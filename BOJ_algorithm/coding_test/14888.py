import sys

n = int(input())
arr_num = list(map(int, sys.stdin.readline().split()))
arr_oper = list(map(int, sys.stdin.readline().split()))
max_result = -1e9
min_result = 1e9


def solution(cal, num_idx, _add, _min, _mul, _div):
    global min_result, max_result
    if num_idx == n:
        min_result = min(cal, min_result)
        max_result = max(cal, max_result)
        return
    if _add:
        solution(cal+arr_num[num_idx], num_idx+1, _add-1, _min, _mul, _div)
    if _min:
        solution(cal-arr_num[num_idx], num_idx+1, _add, _min-1, _mul, _div)
    if _mul:
        solution(cal*arr_num[num_idx], num_idx+1, _add, _min, _mul-1, _div)
    if _div:
        if cal < 0 and arr_num[num_idx] > 0:
            temp_div = abs(cal)//arr_num[num_idx] * -1
            solution(temp_div, num_idx+1, _add, _min, _mul, _div-1)
        else:
            solution(cal//arr_num[num_idx], num_idx +
                     1, _add, _min, _mul, _div-1)


solution(arr_num[0], 1, arr_oper[0], arr_oper[1], arr_oper[2], arr_oper[3])
print(max_result)
print(min_result)
