/************************************************
 * @TITLE : 숫자 카드 2
 * @LEVEL : Silver 4
 * @DATE : 2020-12-16 | 2020-12-19
 * @NUMBER : 10816
 * @URL : https://www.acmicpc.net/problem/10816
 * @TIME : 1sec
 * @MEMORY : 256MB
 * @TIME : 21:36 ~ 2144 2215 ~ 2242 1950 ~ 2030
 ************************************************
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N, M;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    cin >> M;
    for (int i = 0; i < M; i++)
    {

        int input;
        //cin >> input;

        scanf("%d", &input);
        //cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(), arr.end(), input) << ' ';

        int start = 0, end = N, mid;
        int left = 0, right = 0;
        // lower bound
        while (start < end)
        {
            mid = (start + end) / 2;
            if (arr[mid] >= input)
            {
                end = mid;
            }
            else
            {
                start = mid + 1;
            }
        }
        left = end;

        // uppder bound
        start = 0, end = N, mid;
        while (start < end)
        {
            mid = (start + end) / 2;
            if (arr[mid] <= input)
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }
        right = start;

        if (left >= right)
        {
            cout << 0;
        }
        else
        {
            cout << right - left;
        }
        cout << ' ';
        /*
        int findAns;
        scanf("%d", &findAns);
        cout << upper_bound(arr.begin(), arr.end(), findAns) - lower_bound(arr.begin(), arr.end(), findAns) << ' ';
*/
        /*
		vector<int>::iterator low, up;
		low = lower_bound(arr.begin(), arr.end(), findAns);
		up = upper_bound(arr.begin(), arr.end(), findAns);
		
		printf("%d ", up - low);*/
    }
    /*
    for (int i = 0; i < M; i++)
    {
        int input;
        cin >> input;

        cout << upper_bound(arr.begin(), arr.end(), input) - lower_bound(arr.begin(), arr.end(), input) << ' ';

    }*/
}
/*
************************************************
* TEST INPUT 1
************************************************
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10
************************************************
* TEST OUTPUT 1
************************************************
3 0 0 1 2 0 0 2
************************************************
*/

/********************************************************
 * @CATEGORY : 
 * @Hint : updder_bound lower_bound, cin cout 엥간하면 피하자....cin/cout은 입출력 수가 많을수록 비효율적일 수 밖에 없음
 * ******************************************************/
