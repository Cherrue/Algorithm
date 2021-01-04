/************************************************
 * @TITLE : 유기농 배추
 * @LEVEL : Silver 2
 * @DATE : 2021-01-04
 * @NUMBER : 1012
 * @URL : https://www.acmicpc.net/problem/1012
 * @CATEGORY :
 * @TIME : 1sec
 * @MEMORY : 512MB
 * @TIME : 00:01 ~ 00:40
 * @Hint : 길찾기
 ************************************************
*/
#include <iostream>
using namespace std;
int **map;
int M, N;
int findB(int x, int y)
{
    if (x < 0 || x >= M || y < 0 || y >= N)
    {
        return 0;
    }
    if (map[x][y] == 1)
    {
        map[x][y] = 0;
        return 1 + findB(x - 1, y) + findB(x + 1, y) + findB(x, y - 1) + findB(x, y + 1);
    }
    else
    {
        return 0;
    }
}
/*
int findB(int x, int y, int arr[][], int sizeX, int sizeY)
{
    if (x < 0 || x >= sizeX || y < 0 || y >= sizeY)
    {
        return 0;
    }
    if (arr[x][y] == 1)
    {
        arr[x][y] = 0;
        return 1 + findB(x - 1, y, arr, sizeX, sizeY) + findB(x + 1, y, arr, sizeX, sizeY) + findB(x, y - 1, arr, sizeX, sizeY) + findB(x, y + 1, arr, sizeX, sizeY);
    }
    else
    {
        return 0;
    }
}*/
int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        int K;
        scanf("%d%d%d", &M, &N, &K);
        map = new int *[M];
        //int map[M][N];
        for (int j = 0; j < M; j++)
        {
            map[j] = new int[N];
            for (int k = 0; k < N; k++)
            {
                map[j][k] = 0;
            }
        }
        int x, y;
        for (int j = 0; j < K; j++)
        {
            scanf("%d%d", &x, &y);
            map[x][y] = 1;
        }
        int cnt = 0;
        for (int j = 0; j < M; j++)
        {
            for (int k = 0; k < N; k++)
            {
                int a = findB(j, k);
                if (a == 0)
                {
                    continue;
                }
                else
                {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
        for (int j = 0; j < M; j++)
        {
            delete[] map[j];
        }
        delete[] map;
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
2
10 8 17
0 0
1 0
1 1
4 2
4 3
4 5
2 4
3 4
7 4
8 4
9 4
7 5
8 5
9 5
7 6
8 6
9 6
10 10 1
5 5
************************************************
* TEST OUTPUT 1
************************************************
5
1
************************************************

************************************************
* TEST INPUT 2
************************************************
1
5 3 6
0 2
1 2
2 2
3 2
4 2
4 0
************************************************
* TEST OUTPUT 2
************************************************
2
************************************************
*/