/************************************************
 * @TITLE : 나는야 포켓몬 마스터 이다솜
 * @LEVEL : Silver 4
 * @DATE : 2021-01-19
 * @NUMBER : 1620
 * @URL : https://www.acmicpc.net/problem/1620
 * @CATEGORY :
 * @TIME : 2sec
 * @MEMORY : 256MB
 * @TIME : 21:39 ~ 00:35 // 2h 56m
 * @Hint : 
 ************************************************
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct my1620
{
    int order;
    string name;
};
bool compare1620(my1620 a, my1620 b)
{
    if (a.name < b.name)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<my1620> v_order(N);
    vector<my1620> v_name(N);
    for (int i = 0; i < N; i++)
    {
        string input;
        cin >> input;
        my1620 temp = {i, input};
        v_order[i] = temp;
        v_name[i] = temp;
    }
    sort(v_name.begin(), v_name.end(), compare1620);
    for (int i = 0; i < M; i++)
    {
        string test;
        cin >> test;
        if ('0' <= test[0] && test[0] <= '9')
        {
            //find order
            int index = 0;
            for (int j = 0; j < test.length(); j++)
            {
                index *= 10;
                index += test[j] - 48;
            }
            cout << v_order[index - 1].name << "\n";
        }
        else
        {
            //find dict
            int left = 0, right = N - 1;
            int mid = 0;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (test < v_name[mid].name)
                {
                    right = mid - 1;
                }
                else if (test > v_name[mid].name)
                {
                    left = mid + 1;
                }
                else
                {
                    cout << v_name[mid].order + 1 << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}

/*
************************************************
* TEST INPUT 1
************************************************
26 5
Bulbasaur
Ivysaur
Venusaur
Charmander
Charmeleon
Charizard
Squirtle
Wartortle
Blastoise
Caterpie
Metapod
Butterfree
Weedle
Kakuna
Beedrill
Pidgey
Pidgeotto
Pidgeot
Rattata
Raticate
Spearow
Fearow
Ekans
Arbok
Pikachu
Raichu
25
Raichu
3
Pidgey
Kakuna
************************************************
* TEST OUTPUT 1
************************************************
Pikachu
26
Venusaur
16
14
************************************************
*/