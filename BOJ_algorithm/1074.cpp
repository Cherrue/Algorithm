/************************************************
 * @TITLE : Z
 * @LEVEL : Silver 1
 * @DATE : 2021-01-05
 * @NUMBER : 1074
 * @URL : https://www.acmicpc.net/problem/1074
 * @CATEGORY :
 * @TIME : 0.5sec
 * @MEMORY : 512MB
 * @TIME : 00:04 ~ 00:44 / 40m
 * @Hint : 
 ************************************************
*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int N, r, c;
    scanf("%d%d%d", &N, &r, &c);
    int x = pow(2, N - 1), y = pow(2, N - 1);
    int result = 0;
    for (int i = 0; i < N; i++)
    {
        int temp = pow(2, N - 1 - i);
        if (y > r && x > c)
        {
            x -= temp / 2;
            y -= temp / 2;
            result += 0;
        }
        else if (y > r && x <= c)
        {
            x += temp / 2;
            y -= temp / 2;
            result += temp * temp;
        }
        else if (y <= r && x > c)
        {
            x -= temp / 2;
            y += temp / 2;
            result += temp * temp * 2;
        }
        else
        {
            x += temp / 2;
            y += temp / 2;
            result += temp * temp * 3;
        }
    }
    printf("%d", result);
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