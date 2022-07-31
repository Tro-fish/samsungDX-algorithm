#include <iostream>
#include <string>
using namespace std;

#define MAXN 1000

int N;

struct Node
{
    bool isNum;
    int num;
    int children[2];
} nodes[MAXN];

double Calc(int idx)
{
    if (nodes[idx].isNum) // 숫자일 경우 바로 숫자 return
        return (double)nodes[idx].num;
    double c1 = Calc(nodes[idx].children[0]);
    double c2 = Calc(nodes[idx].children[1]);
    switch (nodes[idx].num) // 기호 판별
    {
    case '+':
        return c1 + c2;
    case '-':
        return c1 - c2;
    case '*':
        return c1 * c2;
    case '/':
        return c1 / c2;
    default:
        return -1;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);

    for (int tc = 1; tc <= 10; tc++)
    {
        cin >> N;
        for (int n = 0; n < N; n++)
        {
            int idx;
            cin >> idx;
            idx--;
            string str;
            cin >> str;
            if (str[0] >= '0' && str[0] <= '9') //숫자일 경우
            {
                nodes[idx].isNum = true;
                int num = 0;
                num = stoi(str);
                nodes[idx].num = num;
            }
            else // 기호일 경우
            {
                nodes[idx].isNum = false;
                int num = str[0];
                int c1, c2;
                cin >> c1 >> c2; // 기호일 경우는 left, right도 받아야한다
                c1--;
                c2--;
                nodes[idx].num = num;
                nodes[idx].children[0] = c1;
                nodes[idx].children[1] = c2;
            }
        }
        cout << '#' << tc << ' ' << Calc(0) << '\n';
    }

    return 0;
}