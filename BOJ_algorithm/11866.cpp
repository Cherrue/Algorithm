/************************************************
 * @TITLE : 요세푸스 문제 0
 * @LEVEL : Silver 4
 * @DATE : 2020-12-20
 * @NUMBER : 11866
 * @URL : https://www.acmicpc.net/problem/11866
 * @TIME : 2sec
 * @MEMORY : 512MB
 * @TIME : 0233 ~ 0435 / 양방향 링크드리스트 구현
 ************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
int findIndex(int size, int index)
{
    if (size > index + 2)
    {
        return index + 2;
    }
    else
    {
        if (size == 0)
        {
            return -1;
        }
        else if (size == 1)
        {
            return 0;
        }
        else if (size == 2)
        {
            if (index == 2)
                return 0;
            else
                return 1;
        }
        else
        {
            if (size == index + 1)
            {
                return 1;
            }
            else
            {
                return 2;
            }
        }
    }
}
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }
    //vector<int>::iterator iter = arr.begin();
    int index = 0;

    printf("<");
    for (int i = 0; i <= N - 1; i++)
    {
        if (i != 0)
        {
            printf(", ");
        }
        index = findIndex(arr.size(), index);
        printf("%d", arr[index]);
        arr.erase(arr.begin() + index);
    }
    printf(">");
    return 0;
}*/

struct visitedPoint
{
    int i;
    visitedPoint *next;
    visitedPoint *prev;
};
int main()
{
    int N, K;
    scanf("%d%d", &N, &K);
    visitedPoint *root = new visitedPoint();
    root->i = 1;
    root->next = nullptr;
    root->prev = nullptr;
    visitedPoint *now = root;
    for (int i = 2; i <= N; i++)
    {
        visitedPoint *temp = new visitedPoint();
        temp->i = i;
        temp->next = nullptr;
        temp->prev = now;
        now->next = temp;
        now = now->next;
    }
    now = root;
    while (now->next != nullptr)
    {
        now = now->next;
    }
    now->next = root;
    root->prev = now;

    now = root;
    printf("<");
    for (int i = 1; i <= N; i++)
    {
        visitedPoint *temp = nullptr;
        for (int j = 1; j < K; j++)
        {
            now = now->next;
        }
        temp = now->prev;
        if (i != 1)
        {
            printf(", ");
        }
        printf("%d", now->i);
        temp->next = now->next;
        now->next->prev = temp;
        delete now;
        now = temp->next;
    }
    printf(">");

    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
7 3
************************************************
* TEST OUTPUT 1
************************************************
<3, 6, 2, 7, 5, 1, 4>
************************************************
*/

/********************************************************
 * @CATEGORY : 
 * @Hint : 
 * ******************************************************/