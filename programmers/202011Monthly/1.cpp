#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b)
{
    int answer = 0;

    for (int i = 0; i < a.size(); i++)
    {
        answer += a[i] * b[i];
    }

    return answer;
}

int main()
{
    //vector<int> vect1{1, 2, 3, 4};
    //vector<int> vect2{-3, -1, 0, 2};
    string s = "110010101001";
    vector<int> result = solution(s);
    //cout << result;
    for (int x : result)
        cout << x << " ";
    return 0;
}