/************************************************
 * @TITLE : 피보나치 함수
 * @LEVEL : Silver 3
 * @DATE : 2021-01-04
 * @NUMBER : 1003
 * @URL : https://www.acmicpc.net/problem/1003
 * @CATEGORY :
 * @TIME : 0.25sec
 * @MEMORY : 128MB
 * @TIME : 23:39 ~ 23:59 // 20m
 * @Hint : 시간이 짧다!
 ************************************************
*/
#include <iostream>
using namespace std;
int fib[41] = {0};

void dpfib()
{
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 41; i++)
    {
        fib[i] = fib[i - 2] + fib[i - 1];
    }
}
int main()
{
    int T;
    scanf("%d", &T);
    dpfib();
    for (int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N);
        if (N == 0)
        {
            printf("1 0\n");
        }
        else
        {
            printf("%d %d\n", fib[N - 1], fib[N]);
        }
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
3
0
1
3
************************************************
* TEST OUTPUT 1
************************************************
1 0
0 1
1 2
************************************************
*/