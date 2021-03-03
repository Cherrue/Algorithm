/************************************************
 * @TITLE : 듣보잡
 * @LEVEL : Silver 4
 * @DATE : 2021-03-03
 * @URL : https://www.acmicpc.net/problem/1764
 * @TIME : 2sec
 * @MEMORY : 256MB
 * @TIME : 14:45 ~  15:10 // 25m
 * @Hint : 
 ************************************************
*/
#include <iostream>
#include <set>
#include <string>
using namespace std;
set<string> s;
set<string> result;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string input;
        cin >> input;
        s.insert(input);
    }
    for (int i = 0; i < m; i++)
    {
        string input;
        cin >> input;
        if (s.find(input) != s.end())
        {
            result.insert(input);
        }
    }
    set<string>::iterator iter;
    cout << result.size() << "\n";
    for (iter = result.begin(); iter != result.end(); iter++)
    {
        cout << *iter << "\n";
    }
    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
3 4
ohhenrie
charlie
baesangwook
obama
baesangwook
ohhenrie
clinton
************************************************
* TEST OUTPUT 1
************************************************
2
baesangwook
ohhenrie
************************************************
*/