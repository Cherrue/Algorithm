/************************************************
 * @TITLE : 직사각형에서 탈출
 * @LEVEL : Bronze 3
 * @DATE : 2020-12-07
 * @NUMBER : 1085
 * @URL : https://www.acmicpc.net/problem/1085
 * @CATEGORY : 문제 풀이
 * @TIME : 2sec
 * @MEMORY : 128MB
 * @TIME : 22:08 ~ 22:21
 * @Hint : 
 ************************************************
*/
#include <iostream>
using namespace std;

int setMin(int min, int num)
{
    if (min < num)
    {
        return min;
    }
    return num;
}

int main()
{
    int x, y, w, h;
    cin >> x >> y >> w >> h;
    int min = 1000;
    min = setMin(min, x);
    min = setMin(min, y);
    min = setMin(min, w - x);
    min = setMin(min, h - y);
    printf("%d", min);
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
6 2 10 3
************************************************
* TEST OUTPUT 1
************************************************
1
************************************************
*/