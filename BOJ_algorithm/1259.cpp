/************************************************
 * @TITLE : 팰린드롬수
 * @LEVEL : Bronze 1
 * @DATE : 2020-12-12
 * @NUMBER : 1259
 * @URL : https://www.acmicpc.net/problem/1259
 * @TIME : 1sec
 * @MEMORY : 128MB
 * @TIME : 21:36 ~ 21:47
 ************************************************
*/
#include <iostream>
using namespace std;
int main()
{
    int n;
    int i = 0;
    bool flag = true;
    while (true)
    {
        cin >> n;
        flag = true;
        if (n == 0)
        {
            break;
        }
        int arr[5] = {0};
        for (i = 0; i < 5; i++)
        {
            if (n == 0)
            {
                break;
            }
            arr[i] = n % 10;
            n /= 10;
        }
        for (int j = 0; j <= i / 2; j++)
        {
            if (arr[j] == arr[i - 1 - j])
            {
                continue;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            cout << "yes"
                 << "\n";
        }
        else
        {
            cout << "no"
                 << "\n";
        }
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
121
1231
12421
0
************************************************
* TEST OUTPUT 1
************************************************
yes
no
yes
************************************************
*/

/********************************************************
 * @CATEGORY : 문제 풀이
 * @Hint : 홀수일 때와 짝수일 때
 * ******************************************************/