/************************************************
 * @TITLE : 숨바꼭질
 * @LEVEL : Silver 1
 * @DATE : 2021-03-02
 * @NUMBER : 1697
 * @URL : https://www.acmicpc.net/problem/1697
 * @CATEGORY :
 * @TIME : 2sec
 * @MEMORY : 128MB
 * @TIME : 18:31 ~  // 
 * @Hint : 
 ************************************************
*/
#include <iostream>
#include <queue>
using namespace std;
struct my1697
{
    int first;
    int second;
};
my1697 make_pair(int a, int b)
{
    struct my1697 temp = {a, b};
    return temp;
}
queue<my1697> Q;
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    Q.push(make_pair(n, 0));
    bool ch[100001] = {0};
    while (!Q.empty())
    {
        int m = Q.front().first, l = Q.front().second;
        Q.pop();
        if (m == k)
        {
            cout << l;
            return 0;
        }
        if (m > 100000 || m < 0)
            continue;
        if (!ch[m + 1])
        {
            ch[m + 1] = 1;
            Q.push(make_pair(m + 1, l + 1));
        }
        if (!ch[m - 1])
        {
            ch[m - 1] = 1;
            Q.push(make_pair(m - 1, l + 1));
        }
        if (m * 2 <= 100000 && !ch[m * 2])
        {
            ch[m * 2] = 1;
            Q.push(make_pair(m * 2, l + 1));
        }
    }
    printf("%d", 0);
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
5 17
************************************************
* TEST OUTPUT 1
************************************************
4
************************************************
*/