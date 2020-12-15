/************************************************
 * @TITLE : 카드2
 * @LEVEL : Silver 4
 * @DATE : 2020-12-15
 * @NUMBER : 2164
 * @URL : https://www.acmicpc.net/problem/2164
 * @TIME : 2sec
 * @MEMORY : 128MB
 * @TIME : 11:03 ~ 11:08
 ************************************************
*/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> arr(N + 1);

    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }

    int begin = 1, end = N;
    for (int i = 1; i < N; i++)
    {
        arr[begin] = 0;
        begin++;
        if (begin > N)
        {
            begin -= N;
        }
        end++;
        if (end > N)
        {
            end -= N;
        }
        arr[end] = arr[begin];
        begin++;
        if (begin > N)
        {
            begin -= N;
        }
    }
    cout << arr[end];

    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
6
************************************************
* TEST OUTPUT 1
************************************************
4
************************************************
*/

/********************************************************
 * @CATEGORY : 
 * @Hint : 
 * ******************************************************/