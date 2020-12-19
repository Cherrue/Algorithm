/************************************************
 * @TITLE : 좌표 정렬하기
 * @LEVEL : Silver 5
 * @DATE : 2020-12-20
 * @NUMBER : 11650
 * @URL : https://www.acmicpc.net/problem/2798
 * @TIME : 1sec
 * @MEMORY : 256MB
 * @TIME : 02:00 ~ 0212
 ************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct point
{
    int x;
    int y;
};
bool comparePoint(point a, point b)
{
    if (a.x > b.x)
    {
        return false;
    }
    else if (a.x == b.x)
    {
        if (a.y > b.y)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    else
    {
        return true;
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    vector<point> arr(N);
    for (int i = 0; i < N; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        arr[i].x = x;
        arr[i].y = y;
    }
    sort(arr.begin(), arr.end(), comparePoint);

    for (int i = 0; i < N; i++)
    {
        printf("%d %d\n", arr[i].x, arr[i].y);
    }

    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
5
3 4
1 1
1 -1
2 2
3 3
************************************************
* TEST OUTPUT 1
************************************************
1 -1
1 1
2 2
3 3
3 4
************************************************
*/

/********************************************************
 * @CATEGORY : 
 * @Hint : 
 * ******************************************************/