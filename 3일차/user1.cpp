#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector<char> str_vec;
vector<char> result;
int N;

void inorder(int x)
{
    if (2 * x <= N)
        inorder(2 * x);
    if (x <= N)
        result.push_back(str_vec[x - 1]);
    if (2 * x + 1 <= N)
        inorder(2 * x + 1);
}

int main(void)
{
    cin >> N; // node의 갯수
    for (int i = 1; i <= N; i++)
    {
        int level;
        char charater;
        float left, right;
        cin >> level >> charater;
        if (float(level) == float(N) / 2)
        {
            cin >> left;
            // cout << "level/N == N/2" << endl;
        }
        else if (float(level) < float(N) / 2)
        {
            cin >> left >> right;
            // cout << "level/N < N/2" << endl;
        }
        else
        {
            // cout << "level/N > N/2" << endl;
        }
        str_vec.push_back(charater);
    }
    inorder(1);
    //cout << "#" << test_case << " ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i];
    }
    cout << endl;
    str_vec.clear();
    result.clear();
}