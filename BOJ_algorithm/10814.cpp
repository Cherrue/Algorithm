/************************************************
 * @TITLE : 나이순 정렬
 * @LEVEL : Silver 5
 * @DATE : 2020-12-15
 * @NUMBER : 10814
 * @URL : https://www.acmicpc.net/problem/10814
 * @TIME : 3sec
 * @MEMORY : 256MB
 * @TIME : 00:00 ~ 
 ************************************************
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Info
{
    int age;
    string name;
    int number;
};

bool compareInfo(Info a, Info b)
{
    if (a.age < b.age)
    {
        return true;
    }
    else if (a.age == b.age)
    {
        if (a.number < b.number)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
}

int main()
{
    int N;
    cin >> N;
    vector<Info> arr(N);
    for (int i = 0; i < N; i++)
    {
        int input_age;
        string input_name;
        cin >> input_age >> input_name;
        arr[i].age = input_age;
        arr[i].name = input_name;
        arr[i].number = i;
    }

    sort(arr.begin(), arr.end(), compareInfo);

    for (int i = 0; i < N; i++)
    {
        cout << arr[i].age << ' ' << arr[i].name << '\n';
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
3
21 Junkyu
21 Dohyun
20 Sunyoung
************************************************
* TEST OUTPUT 1
************************************************
20 Sunyoung
21 Junkyu
21 Dohyun
************************************************
*/

/********************************************************
 * @CATEGORY : 
 * @Hint : 
 * ******************************************************/