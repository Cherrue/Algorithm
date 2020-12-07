/************************************************
 * @TITLE : 단어 정렬
 * @LEVEL : Silver 5
 * @DATE : 2020-12-07
 * @NUMBER : 1181
 * @URL : https://www.acmicpc.net/problem/1181
 * @TIME : 2sec
 * @MEMORY : 256MB
 * @TIME : 22:21 ~ 23:48
 ************************************************
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
bool comp(string s1, string s2)
{
    if (s1.length() < s2.length())
        return true;
    else if (s1.length() == s2.length())
        return s1 < s2;
    else
    {
        return false;
    }
}
int main()
{
    int N;
    cin >> N;
    string str_list[N];
    vector<int> checklist;
    for (int i = 0; i < N; i++)
    {
        cin >> str_list[i];
    }
    sort(str_list, str_list + N, comp);

    cout << str_list[0] << "\n";
    for (int i = 1; i < N; i++)
    {
        if (str_list[i - 1].compare(str_list[i]))
            cout << str_list[i] << "\n";
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
13
but
i
wont
hesitate
no
more
no
more
it
cannot
wait
im
yours
************************************************
* TEST OUTPUT 1
************************************************
i
im
it
no
but
more
wait
wont
yours
cannot
hesitate
************************************************
*/



/********************************************************
 * @CATEGORY : 정렬
 * @Hint : algorithm의 sort의 compare 함수에는 여러 가지 조건을 한 번에 줄 수 있음
 * ******************************************************/