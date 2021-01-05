/************************************************
 * @TITLE : 1로 만들기
 * @LEVEL : Silver 3
 * @DATE : 2021-01-05
 * @NUMBER : 1463
 * @URL : https://www.acmicpc.net/problem/1463
 * @CATEGORY :
 * @TIME : 0.5sec
 * @MEMORY : 128MB
 * @TIME : 00:48 ~ 01:13 // 25m
 * @Hint : 
 ************************************************
*/
#include <iostream>
#include <stack>
using namespace std;
struct my1463
{
    int now;
    int cnt;
};
int main()
{
    int N;
    scanf("%d", &N);
    stack<my1463> s;
    int min = N;
    my1463 init = {N, 0};
    s.push(init);
    while (!s.empty())
    {
        my1463 poped = s.top();
        s.pop();
        if (poped.now == 1)
        {
            if (min > poped.cnt)
            {
                min = poped.cnt;
            }
            continue;
        }
        if (poped.cnt >= min)
        {
            continue;
        }
        struct my1463 temp = {poped.now - 1, poped.cnt + 1};
        s.push(temp);
        if (poped.now % 2 == 0)
        {
            struct my1463 temp = {poped.now / 2, poped.cnt + 1};
            s.push(temp);
        }
        if (poped.now % 3 == 0)
        {
            struct my1463 temp = {poped.now / 3, poped.cnt + 1};
            s.push(temp);
        }
    }
    printf("%d", min);

    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
2
************************************************
* TEST OUTPUT 1
************************************************
1
************************************************

************************************************
* TEST INPUT 2
************************************************
10
************************************************
* TEST OUTPUT 2
************************************************
3
************************************************
*/