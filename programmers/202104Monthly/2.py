from collections import deque


def check_brace(a, b):
    if a == '(' and b == ')':
        return True
    elif a == '{' and b == '}':
        return True
    elif a == '[' and b == ']':
        return True
    else:
        return False


def solution(s):
    answer = 0
    str_test = s
    for i in range(len(s)):
        stack_check = deque()
        for c in str_test:
            if stack_check:
                top = stack_check.pop()
                if not check_brace(top, c):
                    stack_check.append(top)
                    stack_check.append(c)
            else:
                stack_check.append(c)
        if not stack_check:
            answer += 1

        str_test = str_test[1:]+str_test[0]
    return answer


print(solution("}]()[{"))
