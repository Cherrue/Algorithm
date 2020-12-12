/************************************************
 * @TITLE : 수 찾기
 * @LEVEL : Silver 4
 * @DATE : 2020-12-12
 * @NUMBER : 1920
 * @URL : https://www.acmicpc.net/problem/1920
 * @TIME : 2sec
 * @MEMORY : 128MB
 * @TIME : 23:37 ~ 00:21
 ************************************************
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> num;

int quickFind(int size_A, int find_num)
{
    int start = 0;
    int fin = size_A;
    int mid;
    while (true)
    {
        if (start > fin)
        {
            break;
        }
        mid = (start + fin) / 2;
        if (num[mid] > find_num)
        {
            fin = mid - 1;
        }
        else if (num[mid] == find_num)
        {
            return 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return 0;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N;
    num = vector<int>(N);
    for (int i = 0; i < N; i++)
    {
        cin >> num[i];
    }

    sort(num.begin(), num.end());

    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int temp;
        cin >> temp;
        cout << quickFind(N, temp) << "\n";
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
5
4 1 5 2 3
5
1 3 7 9 5
************************************************
* TEST OUTPUT 1
************************************************
1
1
0
0
1
************************************************
*/

/********************************************************
 * @CATEGORY : 이진탐색
 * @Hint : 빨리 찾는건 이진탐색, vector는 인자로 넘기면 굉장히 느리다!!
 * ******************************************************/