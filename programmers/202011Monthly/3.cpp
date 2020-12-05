#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int solution(std::vector<int> a)
{
    int answer = 0;

    sort(a.begin(), a.end());

    vector<int> counts;
    int before = a[0];
    int count = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (a[i] == before)
            count++;
        else
        {
            counts.push_back(count);
            count = 1;
            before = a[i];
        }
    }

    counts.push_back(count);
    sort(counts.begin(), counts.end());

    int max = counts[counts.size() - 1];
    if (max > a.size() / 2)
        max = a.size() / 2;
    for (int i = counts.size() - 2; i >= 0; i--)
    {
        if (answer >= max)
        {
            answer = max;
            break;
        }
        if (counts[i] <= max / 2)
        {
            answer += counts[i];
        }
        else
        {
            answer += max / 2;
        }
    }

    return answer * 2;
}

int main()
{
    vector<int> vect1{1, 2, 1, 2, 1, 2};
    //vector<int> vect2{-3, -1, 0, 2};
    //vector<int> result = solution(vect1);
    //for (int x : result)
    //    cout << x << " ";
    int result = solution(vect1);
    cout << result;
    return 0;
}