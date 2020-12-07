/************************************************
 * @TITLE : 체스판 다시 칠하기
 * @LEVEL : Silver 5
 * @DATE : 2020-12-05
 * @NUMBER : 1018
 * @URL : https://www.acmicpc.net/problem/1018
 * @CATEGORY : burte-force
 * @TIME : 2sec
 * @MEMORY : 128MB
 * @TIME : 15:13 ~ 16:39 // vscode 설정으로 굉장히 지연...
 * @Hint : 입력 최대값과 시간을 비교해보면 다해보기전략(brute-force)임을 유추 가능
 ************************************************
*/
#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    char arr[N][M];
    int cnt1 = 0;
    int cnt2 = 0;
    int smaller = 0;
    int min = 64;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i <= N - 8; i++)
    {
        for (int j = 0; j <= M - 8; j++)
        {
            cnt1 = 0;
            cnt2 = 0;
            smaller = 0;
            for (int p = 0; p < 8; p++)
            {
                for (int q = 0; q < 8; q++)
                {
                    if ((p + q) % 2 == 0)
                    {
                        if (arr[i + p][j + q] == 'W')
                        {
                            cnt1++;
                        }
                        else
                        {
                            cnt2++;
                        }
                    }
                    else
                    {
                        if (arr[i + p][j + q] == 'W')
                        {
                            cnt2++;
                        }
                        else
                        {
                            cnt1++;
                        }
                    }
                }
            }
            smaller = cnt2 > cnt1 ? cnt1 : cnt2;
            if (smaller < min)
            {
                min = smaller;
            }
        }
    }

    printf("%d", min);
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
8 8
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBBBWBW
WBWBWBWB
BWBWBWBW
WBWBWBWB
BWBWBWBW
************************************************
* TEST OUTPUT 1
************************************************
1
************************************************

************************************************
* TEST INPUT 2
************************************************
10 13
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
BBBBBBBBWBWBW
BBBBBBBBBWBWB
WWWWWWWWWWBWB
WWWWWWWWWWBWB
************************************************
* TEST OUTPUT 2
************************************************
12
************************************************
*/