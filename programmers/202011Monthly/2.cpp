#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>

#include <bitset>

using namespace std;

vector<int> solution(string s)
{
    vector<int> answer;
    int init_length = s.length();
    string temp;
    int cnt = 0;
    int cnt2 = 0;
    int flag = 0;
    int first_flag = 0;
    bitset<150000> mybit;
    if (s.length() == 1)
    {
        answer.push_back(0);
        answer.push_back(0);
        return answer;
    }
    while (1)
    {
        flag = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
            {
                temp.push_back('1');
                flag = 1;
            }
            else
            {
                if (first_flag == 0)
                {
                    cnt++;
                }
                else if (flag == 1)
                {
                    cnt++;
                }
            }
        }
        first_flag = 1;
        cnt2++;
        if (temp.length() == 1)
        {
            answer.push_back(cnt2);
            answer.push_back(cnt);
            break;
        }
        mybit = bitset<150000>(temp.length());
        s = mybit.to_string<char, string::traits_type, string::allocator_type>();
        temp.clear();
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