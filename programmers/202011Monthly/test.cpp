#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

using namespace std;

vector<int> solution(vector<int> numbers)
{
    vector<int> answer;
    for (int i = 0; i < numbers.size(); i++)
    {
        for (int j = i + 1; j < numbers.size(); j++)
        {
            answer.push_back(numbers[i] + numbers[j]);
        }
    }

    unordered_set<int> s;
    for (int i : answer)
        s.insert(i);
    answer.assign(s.begin(), s.end());
    sort(answer.begin(), answer.end());
    return answer;
}

int main()
{
    vector<int> vect{2, 1, 3, 4, 1};
    vector<int> result = solution(vect);

    for (int x : result)
        cout << x << " ";
    return 0;
}