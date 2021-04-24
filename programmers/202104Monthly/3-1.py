from collections import deque


def solution(a, edges):
    if sum(a) != 0:
        return -1

    graph = {}
    for edge in edges:
        if edge[0] in graph.keys():
            graph[edge[0]].append(edge[1])
        else:
            graph[edge[0]] = [edge[1]]
        if edge[1] in graph.keys():
            graph[edge[1]].append(edge[0])
        else:
            graph[edge[1]] = [edge[0]]
    result = 0
    bfs = deque()
    bfs.append(0)
    bool_a = [False]*len(a)
    bool_a[0] = True
    while bfs:

        top = bfs.popleft()
        for i in graph[top]:
            if a[top]*a[i] < 0:
                if abs(a[top]) > abs(a[i]):
                    result += abs(a[i])
                    a[top] += a[i]
                    a[i] = 0
                elif abs(a[top]) < abs(a[i]):
                    result += abs(a[top])
                    a[i] += a[top]
                    a[top] = 0
                else:
                    result += abs(a[top])
                    a[top] = 0
                    a[i] = 0
            if not bool_a[i]:
                bool_a[i] = True
                bfs.append(i)

        end_flag = True
        for i in range(len(a)):
            if a[i] != 0:
                end_flag = False
        if end_flag:
            break

        for i in graph[top]:
            dfs = deque()
            check_dfs = [False]*len(a)
            check_dfs[i] = True
            check_dfs[top] = True
            dfs.append(i)
            find_flag = False
            while not find_flag and dfs:
                seek_top = dfs.pop()
                for j in graph[seek_top]:
                    if not check_dfs[j]:
                        if a[j] != 0:
                            find_flag = True
                        dfs.append(j)
            if find_flag:
                result += abs(a[top])
                a[i] += a[top]
                a[top] = 0
                break

    return result


'''
        if sum(adj_list[top]) == 1:
            for i in range(len(a)):
                if adj_list[top][i] == 1:
                    result += abs(a[top])
                    a[i] += a[top]
                    a[top] = 0
                    break
            continue

        if a[top] < 0:
            min_value = 0
            min_idx = -1
            for i in range(len(a)):
                if i == top:
                    continue
                if min_value > a[i]:
                    min_value = a[i]
                    min_idx = i
            if min_idx > -1:
                result += abs(a[top])
                a[min_idx] += a[top]
                a[top] = 0
        elif a[top] > 0:
            max_value = 0
            max_idx = -1
            for i in range(len(a)):
                if i == top:
                    continue
                if max_value < a[i]:
                    max_value < a[i]
                    max_idx = i
            if max_idx > -1:
                result += abs(a[top])
                a[max_idx] += a[top]
                a[top] = 0
'''


solution([-5, 0, 2, 1, 2], [[0, 1], [3, 4], [2, 3], [0, 3]])
# solution([1, 0, -1, 0], [[0, 1], [1, 2], [2, 3], [0, 3]])
# [-5,0,2,1,2]	[[0,1],[3,4],[2,3],[0,3]]	9
